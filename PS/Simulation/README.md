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

## BOJ#14503 로봇 청소기
#### Overview
An N-by-M matrix filled with 1 as a wall and 0 as a path and the precedure
of how the robotic vacuum runs are given.

1. Clean current grid
2. Probe adjacent grids in counter clock-wise starting from the left grid of 
the current direction  
  a. If the grid being probed is not cleaned, change direction to the grid and
     go forward for one grid and repeat Step 1.  
  b. If all four adjacent grids are cleaned up, keep current direction and go
     backward for one grid.
  c. If it cannot go backward, stop working.

#### Trials
At every step, the output is stored in `State` that consists of `y`, `x`, and
`dir`. `y` and `x` represents the position, and `dir` shows the direction of 
the state. In addition, in order to simulate the special probing precedure, an
extra layer of abstraction between probing iterator and the next direction. The 
whole precedure is implemented in iterative version; however, it could be bit 
simpler in recursive version.

## BOJ#16234 인구 이동
#### Overview
- Givens
  - N-by-N matrix represents residential areas with the number of population
  - `L` and `R` indicates the lower and upper bound to open the area border
- Population movement mechanism
  - If the difference in the number of population between two adjacent areas is 
  in between `L` and `R`, the border is open for a day
  - The areas that are connected throught the open border are considered *united*
  - After border opening process is done, population move starts. 
  - After population movement is done, the population of all *united* areas 
  becomes **(total number of population / the number of areas in the *united* 
  area)**
  - Close borders and day ends

It simulates the above mechanism and gives the number of days to complete the
population movement.

#### Trials
Considering the given matrix as a graph, it finds the connected components with
BFS algorithm. The connected component is the *united* areas; therefore, the 
number of nodes in the connected component corresponds the number of areas. As 
there might be many independent connected components, the global `visited` 2D
vector is used to exhaust all of them.

## BOJ#16235 나무 재테크
#### Overview
An N-by-N matrix represents the land of tree growing. Each grid has a number 
that represents its fertility and can contain many trees. The initial fertility
of each grid is five. Trees grow as the following mechanism:
- Spring  
   Trees grow by a year as they consume fertility of their grid as much as their
   current age. If the fertility is not enough, trees that cannot get nutrients
   die immediately. If there are multiple trees in a grid, the youngest eats up
   first.
- Summer  
   The dead trees become nutrients adding fertility by its `age / 2`.
- Fall  
   Multiple-of-5 aged trees reproduce age-1 trees into its eight adjacents grids.
- Winter  
   Fertility is added by the given N-by-N matrix `A`.

#### Trials
For readability and modularity, the source code is split into `spring()`, 
`summer()`, `fall()`, `winter()` as the instruction. Initially, `priority_queue`
as min heap is used to effectively pick the youngest tree in a grid for every
iteration. This approach is obviously faster than the way that a list having 
tree information is sorted for every iteration. However, `deque` makes it even
faster. In fact, it requries only one sorting at the beginning. The FIFO(First
In, First Out) chacteristic of queue and accessibility to the back of the queue
with `deque` allow it to keep the descending order in tree age.

## BOJ#17144 미세먼지 안녕!
#### Overview
An R-by-C matrix representing a house floor having an air cleaner(two grids of 
`-1`) and some amount of dusts(`A[r][c]`) is given. At every second, the 
following events happens:
- Dusts diffuse
   - Dust diffuse into four adjacent grids.
   - If the adjacent grid is out of bound or has the air cleaner, they don't
   diffuse.
   -  Dusts diffuse by `A[r][c] / 5` amount, and the amount of dusts at the 
   original grid becomes `A[r][c] - A[r][c] / 5 * Number of diffusion`.
- The air cleaner runs
   - The air from the upper part of the air cleaner flows in counter-clockwise,
   and the other flows in clockwise.
   - Dusts move by one grid in air flow direction
   - The air from the cleaner has zero dust, and the dusts sucked in it are cleaned.
The air cleaner is always places at the first column. 

#### Trials
In *Diffusion* part, the tricky part is how to keep track of the original value.
In fact, iterating the matrix in row major order, the value of the next grids
that haven't yet visited is changed by the diffusion from its adjacent grids.
This causes unexpected output of the diffusion. Therefore, the original values 
of the matrix are copied at the beginngin and are used as a reference.   
In addition, the key of the other part of the problem is to manipulate the matrix. 
The matrix is divided into two parts:
<p align="center">
    <img width="50%" src="https://upload.acmicpc.net/94466937-96c7-4f25-9804-530ebd554a59/-/preview/">
</p>
The outer shell of upper matrix rotates in counter-clockwise, and one of lower
matrix rotates in clockwise. 