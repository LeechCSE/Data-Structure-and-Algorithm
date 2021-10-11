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