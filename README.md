# CSAPP-Labs

Just the labs. Some of my explanations for the code are in the comment. 

# To-do List

- [x] Data Lab
- [x] Bomb Lab
- [x] Attack Lab
- [x] Y86 Simulator
- [x] Y86 Assembler
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
*4*|*4*|*0*|*2*|*43/90*|`howManyBits`
4|4|0|2|9|`floatScale2`
*4*|*4*|*0*|*2*|*24*|`floatFloat2Int`
0|4|1|0|11|`floatPower2`

Score = `56/62` [ `32/36` Corr + `24/26` Perf ] &emsp;  (162 total operators)

### Note

- I'm pretty sure something's wrong with the test sequence for `floatPower2`, causing the TLE. I compiled it with gcc and it worked fine.
- Lines with *italic* indicate that I wasn't able to solve the puzzle independently.

## Bomb Lab (10/17/2020)

Six phases & secret phase completed. No explosions. My solution is in `/bomblab/crack.txt` and the explanation for each phase is in `/bomblab/explanation`.

## Attack Lab (10/24/2020)

5 levels completed. My solution is in `/attacklab/solution`.

## Y86 Simulator (03/03/2021)

Score for instructions: 33/33

Score for applications: 40/40

Total score:            73/73

## Y86 Assembler (03/11/2021)

Score for instructions: 33/33

Score for error-handling cases: 8/8

Score for applications: 40/40

Total score:            81/81
