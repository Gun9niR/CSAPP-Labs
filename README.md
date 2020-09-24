# CSAPP-Labs
Just the labs. Some of my explanations for the code are in the comment. 

# To-do List
- [x] Data Lab
- [ ] Bomb Lab
- [ ] Attack LAb
- [ ] Cache Lab
- [ ] Shell Lab
- [ ] Malloc Lab
- [ ] Proxy Lab

# Scores
## Data Lab (9/24/2020)
Correctness Points| Results Rating| Errors | Perf Results Points | Ops Used |Puzzle
:---:|:---:|:---:|:---:|:---:|:---:
1|1|0|2|8/14|`bitXor`
1|1|0|2|1/4|`tmin`
1|1|0|2|9/10|`isTmax`
2|2|0|2|7/12|`allOddBits`
2|2|0|2|2/5|`negate`
3|3|0|2|14/15|`isAsciiDigit`
3|3|0|2|8/16|`conditional`
3|3|0|2|14/24|`isLessOrEqual`
4|4|0|2|12/12|`logicalNeg`
<font color=red>4</font>|<font color=red>4</font>|<font color=red>0</font>|<font color=red>2</font>|<font color=red>43/90</font>|`howManyBits`
4|4|0|2|9|`floatScale2`
<font color=red>4</font>|<font color=red>4</font>|<font color=red>0</font>|<font color=red>2</font>|<font color=red>24</font>|`floatFloat2Int`
0|4|1|0|11|`floatPower2`


<font size=4>Score = `56/62` [ `32/36` Corr + `24/26` Perf ] &emsp;  (162 total operators)</font>

### Note:
- I'm pretty sure something's wrong with the test sequence for `floatPower2`, causing the TLE. I compiled it with gcc and it worked fine.
- Lines colored red indicate that I wasn't able to solve the puzzle independently.
