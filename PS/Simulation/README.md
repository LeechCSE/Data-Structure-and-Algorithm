# Problem Solving: Simulation

## BOJ#14499 주사위 굴리기
#### Overview
Given a N-by-M matrix filled with an integer per grid and a dice, 
roll-instructions(either to the north, south, east, or west) are executed.
At each instruction, if the integer of grid where the dice is on is 0, the
bottom face of the dice is copied to the grid; otherwise, the gird integer
is copied to the bottom face of the dice and becomes 0. Initially, all faces
of the dice have 0.
#### Trials
Simple simulation problem. `Dice` is implemented.
```
----------------
|     Dice     |
|--------------|
|-bot          |
|-up           |
|-east         |
|-west         |
|-north        |
|-south        |
|--------------|
|+roll_north() |
|+roll_south() |
|+roll_east()  |
|+roll_west()  |
----------------
```
Each members represents each face of the dice, and the methods changes the
faces after corresponding roll. Technically, since `Dice` is not a class but 
a struct, the members of `Dice` are not private. In order to effectively show 
the structure of `Dice` in UML diagram, they are labeled that so.

## BOJ#14891 톱니바퀴
#### Overview
Given four gears interlocked and `K` operations in `(Gear#, Dirction)` format,
it gives the final state of the gears after `K` operations.

<p align="center">
    <img src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14891/4.png">
</p>

Shown in the above image, the adjacent teeth are interlocked. Starting from 
the given `Gear#`, it "propagates" rotating operation into adjacent gears. In
this example, the op-code is `(3, 1)`, meaning "rotate 3rd gear in clock-wise."
If the magnetic pole of the adjacent tooth of 2nd and 4th are the same, they
don't rotate and stop propagating into the next gear; otherwise, they rotate and
propagate into the next gear.

#### Trials
In order to implement the rotation, `shift` operation with `bitset` data
structure is used. More specifically, the circular shift is implemented. The 
most complicated part of this problem is to propagate the operation. At this time, 
`propagate()` is hard-coded for four gears; it is not scalable!