# Problem Solving: Simulation

## BOJ#14499 주사위 굴리기
#### Overview
Given a N-by-M matrix filled with an integer per grid and a dice, 
roll-instructions(either to the north, south, east, or west) are executed.
At each instruction, if the integer of grid where the dice is on is 0, the
bottom face of the dice is copied to the grid; otherwise, the gird integer
is copied to the bottom face of the dice and becomes 0. Initially, all faces
of the dice have 0.
#### Trials & Solution
Simple simulation problem. `Dice` is implemented.
```
+--------------+
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
+--------------+
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

#### Trials & Solution
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

#### Trials & Solution
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

#### Trials & Solution
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

#### Trials & Solution
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

#### Trials & Solution
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

## BOJ#17143 낚시왕
#### Overview
A fisherman goes fishing in an R-by-C matrix pool having a shark per a grid.

<p align="center">
    <img width="50%" src="https://upload.acmicpc.net/85c2ccad-e4b8-4397-9bd6-0ec73b0f44f8/-/preview/">
</p>

At every second, the following events happen:
- Starting from the very left side, the fisherman moves toward right by one column
- The fisherman catches the closest shark from the ground
- The sharks move
   - Each shark has its speed(grid per second), size, and direction(1: up, 
   2: down, 3: right, 4: left).
   - If sharks move out of the pool, they change their direction into the 
   opposite keeping their speed
   - If there are multiple sharks in a grid, the biggest survives.
Eventually, there is one shark per gird. It ends when the fisherman reaches the
end of the pool.

#### Trials & Solution
The pool is designed in two-dimensional `vector` with `queue` of `Shark`: `vector<vector<queue<Shark>>>`.
The 2-D vector represents the physical pool itself. The queue works as a buffer
that holds the sharks that arrive at the gird until all sharks' moving is done.
The buffer is freed after figuring out the biggest shark in the grid. `Shark`
data structure has four member variables: `speed`, `direction`, `size`, and 
`is_updated`. The first three variables are as given, and `is_updated` indicates
whether this shark is originally from the grid or not. This flag prevents from
iterating the same shark more than once in one iteration.
```
The structure of Shark
+---------------+
|     Shark     |
|---------------|
|-speed         |
|-direction     |
|-size          |
|-is_updated    |
|-north         |
|-south         |
|---------------|
|+Shark()       |
|+Shark(...)    |
|+operator==    |
|+operator!=    |
+---------------+
```

## BOJ#17780 새로운 게임
#### Overview
Given an N-by-N chess `board` and `K` pieces with the order of iteration, each
piece moves as the given rule, and the game ends when four pieces are stacked.
The rule is given as the following:
- A grid can have multiple pieces stacked up each other in FIFO(First In First
Out) manner.
- *move* means that the whole stack, not the sole piece, moves.
1. If the color of grid where `piece-X` moves to ...  
   1. White, move by one grid in the given direction of `piece-X`.  
   2. Red, reverse the order of stack and move by one grid in the given direction 
   of `piece-X`.
   3. Blue, flip the direction and go back to *Step 1*. If `piece-X` encounter 
   Blue again, stay.
   
#### Challenges
Simulation problems typically require turn-by-turn technique. In fact, some given
data are referred and altered during the iteration at the same time. While they 
are changed, the original values are looked up by the function; therefore, the 
original ones must be protected. It is very hard to keep track of what is altered
and what should be protected.
#### Trials & Solution
The folowing are data structures made for solving this problem:
- `Piece`: data structure that has members of `position` and `direction`.
- `board`: contains the color of grid
- `arrangement`: indicates the arrangement of `Pieces` by their id stored in `deque`
- `pieces`: simple vector of `Piece` keeping track of the order of iteration by its
index.

For each turn, `play()` method that simulates the game is called. Mentioned in
*Challenge* section, the idea of separating data to be altered from ones to be
protected is persued using call-by-value and call-by-reference.

## BOJ#20061 모노미노모미노 2
#### Overview
<p align="center">
    <b>Game board</b> <br />
    <img width="50%" src="https://upload.acmicpc.net/8043086d-a85c-4d9e-8505-7a4ffd8c4439/-/preview/"> 
    <br />
    <b>Three types of block</b>
    <br />
    <img width="20%" src="https://upload.acmicpc.net/1453b25c-e0c1-4b99-9eda-bba9336beab1/-/preview/">
</p>

With the above board given, the game is just like Tetris but in two ways. At each
turn, one of the three different blocks are placed in `Red` zone. Then, it moves
down to `Green` zone and right to `Blue` zone and is stacked up if there are other
blocks under it. If whole lines are filled, they is removed, and the blocks above
them are shifted down by the number of lines removed. Just like Tetris! Special
zone makes this game different from Tetris. It is in `0` and `1` lines of each 
`Green` and `Blue` board. If even a grid of the special zone is filled, blocks
are removed by the number of lines filled. For example, if `Blue[1][2]` and
`Blue[0][1]` are filled, it counts two lines of the special zone are filled.
Therefore, Row 5 and 4 of `Blue` are removed.

#### Trials & Solution
```
+-----------------+
|      Domino     |
|-----------------|
|-red             |
|-blue            |
|-green           |
|-place1()        |
|-place2()        |
|-place3()        |
|-filled()        |
|-shift_right()   |
|-shift_down()    |
|-----------------|
|+Domino()        |
|+place()         |
|+score()         |
|+special_check() |
+-----------------+

```
The whole process is the following:
- Create a game
   - With the constructor `Domino()`, a new game is set up; `Red`, `Blue`, and
   `Green` boards are individually created as given size.
- Place a block
   - `place()` method is a wrapper function of `place1()`, `place2()`, and 
   `place3()`. The type of block determines which method is used.
- Score
   - `score()` method checks whether lines are filled or not with `filled()`
   private method. In that case, shifting occurs by `shift_right()` and/or 
   `shift_down()` depending on the board.
- Check the special zone
   - At last, `special_check()` checks if any of special grids is filled. If
   filled, shifting occurs.
   
## 2018 Kakao Blind Recruitment: 셔틀버스
#### Overview
`n` shuttle buses depart every `t` minutes starting at 09:00. Arriving the station, 
the shuttle takes `m` people in the line and departs immediately. Given the 
arrive-time of people in the line(`timetable`), it computes the lastest time 
to line up.

**Example**

| n | t | m | timetable | answer |
|:-:|:-:|:-:|:--------- |:------:|
| 1 | 1 | 5 | ["08:00", "08:01", "08:02", "08:03"] | "09:00" |
| 2 | 10| 2	| ["09:10", "09:09", "08:00"] | "09:09"
| 2 | 1 | 2	| ["09:00", "09:00", "09:00", "09:00"] | "08:59"
| 1 | 1 | 5	| ["00:01", "00:01", "00:01", "00:01", "00:01"] |	"00:00"
| 1	| 1	| 1	| ["23:59"] | 	"09:00"
| 10| 60| 45| ["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"] | "18:00"
#### Trials & Solution
In order to get the lastest time to line up, it need to check whether the last 
shuttle is full or not. In fact, if it is not full, the lastest time would be
the arrive-time of the last shuttle; otherwise, it would be "slightly earlier"
than arrive-time of the last person in the line. In this case, it is one minute
ealier. Since the last shuttle matters, shuttles are populated from the first shuttle.
The shuttles are abstracted with `map<int, vector<string>>`. Each shuttle is 
represented by its arrive-time, and `vector<string>` indicates the seats; its
elements are line-up-time of people.

| n | t | m | timetable | answer |
|:-:|:-:|:-:|:--------- |:------:|
| 2 | 10| 2	| ["09:10", "09:09", "08:00"] | "09:09"

The above example's output woule be
```
Shuttle 09:00 : "08:00"
Shuttle 09:10 : "09:09", "09:10"
```

## 2018 Kakao Blind Recruitment: 프렌즈4블록
#### Overview
Given an M-by-N matrix filled with characters, 2x2 blocks of the same characters,
called `Friends4Block`, are eliminated, and the blocks stacked above the eliminated 
are dropped down. It continues until no `Friends4Block` exists in the board. It 
computes the number of blocks eliminated.

**Example:**
<p align="center">
    <img src="http://t1.kakaocdn.net/welcome2018/pang1.png">
    <img src="http://t1.kakaocdn.net/welcome2018/pang2.png">
    <img src="http://t1.kakaocdn.net/welcome2018/pang3.png">
    <img src="http://t1.kakaocdn.net/welcome2018/pang4.png">
</p>

#### Trials & Solution
In this problem, there are two main mechanisms: check and eliminate. These two
mechanisms are repeated until no `Friends4Block` remains. First, iterating all
elements, it stores all positions of a `Friends4Block` in `set` for all 
`Friends4Blocks`. Since multiple `Friends4Blocks` can share their members with each 
other, `set` can pick the duplicates out when storing, which is efficient!
Then, elimination part is straightforward. For all elements in the `set`, which 
represents all positions of `Friends4Blocks`, it replaces the elements with 
the above elements.

## 2018 Kakao Blind Recruitment: 압축
#### Overview
It simulates LWZ compression only for capital alphabet letters(A-Z).
LWZ compression procedure:
1. Initialize dictionary for all length-1 letters.
2. Find the longest string `w` that contains the current input in the dictionary.
3. Print index number of `w` and remove `w` from the current input.
4. If there exists the remaining input `c`, add `w + c` to the dictionary.
5. Go to *Step 2*.

#### Trials & Solution
The procedure is given cleary; therefore, implementing LWZ compression is straighforward.
The dictionary of LWZ is abstracted with `map<string, int>`. The reason why
`string` is used as a key, not `int` that is the index number is to utilize
`find()` method of `map` effectively. At each iteration, sub-string of given 
message, which is to be compressed, is looked up, and the index number is outputed.
Although the dictionary in the description has `<index, string>` format, the swapped
data structure is more effective in implementation.

## 2018 Kakao Blind Recruitment: 파일명 정렬
#### Overview
Filename consists of three components:
- `HEAD`: non-digit alphabet with special characters (" ", ".", and "-"). At
    least one character.
- `NUMBER`: one to five digit number at maximum. it can have leading zeros.
- `TAIL`: the rest part.

Example
```          
            |  HEAD | NUMBER | TAIL
------------+-------+--------+------
"img12.png" |  img  |   12   | .png          
"img10.png" |  img  |   10   | .png
"img02.png" |  img  |   02   | .png
"img1.png"  |  img  |   1    | .png
"IMG01.GIF" |  IMG  |   01   | .GIF
"img2.JPG"  |  img  |   2    | .JPG

```
Sorting rule:
- Sort `HEAD` alphabetically ignoring capitalization. 
- if same `HEAD` but capitalization, compare `NUMBER` as integers ignoring leading zeros.
- if `NUMBER` doesn't make difference, keep the given order.

Example(`HEAD` ignoring capitalization, `NUMBER` ignoring leading zeros)
```          
            |  HEAD | NUMBER | TAIL
------------+-------+--------+------
"img1.png"  |  img  |   1    | .png
"IMG01.GIF" |  img  |   1    | .GIF
"img02.png" |  img  |   2    | .png
"img2.JPG"  |  img  |   2    | .JPG
"img12.png" |  img  |   12   | .png          
"img10.png" |  img  |   10   | .png

Given:  ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
Sorted: ["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"]
```
#### Trials & Solution
First, the given filenames are splited into tokens: `HEAD`, `NUMBER`, and `TAIL`. 
In sorting process, each token is treated differently; therefore, spliting is the
most efficient way to solve the problem. Then, sort the files as the given rule 
using `stable_sort()` of `<algorithm>` library. The reason why `stable_sort()` 
instead of `sort()` is used is to guarantee the original order of the given files
when both `HEAD` and `NUMBER` don't make differece in sorting. In addition, when
sorting based on `NUMBER`, `stoi()` cannot be used. In order to ignore leading zeros,
`stoi()` method is a handy way; however, the filename can be 100 long, meaning that
`NUMBER` can be <img src="https://latex.codecogs.com/svg.image?\inline&space;10^{98}" title="\inline 10^{98}" />.
In this case, none of `sto*()`, even `stoull()`, which converts `string` to 
`unsigned long long`, can handle that long number. Therefore, leading zeros are
parsed in spliting procedure, and `NUMBER` is treated as pure `string`.

## 2018 Kakao Blind Recruitment: 방금 그 곡
#### Overview
Given notes of a part of song(`C, C#, D, D#, E, F, F#, G, G#, A, A#, B`) and
a list of song information broadcasted on the radio, it finds the song matched
with the given notes. Each note takes one minute.
```
Given: 
  Target song: CC#BCC#BCC#BCC#B	
  List of songs: ["03:00, 03:30, FOO, CC#B", "04:00, 04:08, BAR, CC#BCC#BCC#B"]
  
Song1 plays for 30 minutes with CC#B notes => CC#BCC#BCC#BCC#BCC#BCC#BCC#BCC#BCC#BCC#B
Song2 plays for 8 minutes with CC#BCC#BCC#B. The whole notes aren't able to be
played in 8 minutes => CC#BCC#BCC#.

Answer: FOO
```
#### Trials & Solution
Each information of the given list of songs is parsed into `Info` struct.
```
struct Info{
    int play_time;
    string title, note;
};
```
`play_time` is the amount of time played for the song and is obtained from 
`end time - start time`. `title` is the title of the song from the 3rd token. 
`note` is all notes played during `play_time`. If the length of given note is 
shorter than `play_time`, repeated notes are played; otherwise, given notes are cut.
One tricky part of this problem is the existence of `#`. It leads to the difference
between the length of notes and the play time due to the `#`. For example, for 
`CC#B` notes, the length is 4; however, the play time is 3(`C`, `C#`, and `B`). 
In addition, when matching with the target notes, another problem arises.
Using `find()` method of `string` library, `CCB` is found twice in `CCB#CCB`.
However, the first found of `[CCB]#CCB` is incorrect due to `#`.

## 2019 Kakao Blind Recruitment: 오픈채팅방
#### Overview
Given raw logs of an open chatroom recorded chronologically, it gives the 
modified logs. The logs are among: 
- `Enter user-id nickname`: indicates the user with `user-id` entered with `nickname`.
    If the same user enters for multiple times with different nickname, the last
    one is taken.
- `Leave user-id`: indicates the user with `user-id` left.
- `Change user-id nickname`: indicates the user with `user-id` changed his/her nickname to `nickname`.
    If the user changes his/her nickname for multiple times, the last nickname is taken.

```
"Enter uid1234 Muzi"   => "Prodo님이 들어왔습니다." (Change op)
"Enter uid4567 Prodo"  => "Ryan님이 들어왔습니다." (Multiple Enter op)
"Leave uid1234"        => "Prodo님이 나갔습니다."
"Enter uid1234 Prodo"  => "Prodo님이 들어왔습니다."
"Change uid4567 Ryan"
```
#### Trials & Solution
The given log is tokenized into `Message` with members of `op`, `id`, and `nickname`.
First, iterating given logs, it adds mapping between user id and nickname into 
`map` of `<user-id, nickname>` pair unless `op` is `Leave`. Then, in another 
iterations of logs, it prints out the modified logs referring to the user-id-nickname
hash map.

## 2019 Kakao Blind Recruitment: 실패율
#### Overview
Given the number of stages `N` and the number of players at each stage, it gives
the list of stages sorted by the failure rate in increasing order.  
<img src="https://latex.codecogs.com/svg.image?\inline&space;Failure\&space;rate\&space;of\&space;StageX&space;=&space;\frac{The\&space;number\&space;of\&space;unclears}{The\&space;number\&space;of\&space;players\&space;who\&space;reach\&space;StageX}" title="\inline Failure\ rate\ of\ StageX = \frac{The\ number\ of\ unclears}{The\ number\ of\ players\ who\ reach\ StageX}" />
#### Example
| N | Stages | Results |
|:-:|:-------|:--------|
| 2 | [2, 1, 2, 6, 2, 4, 3, 3] | [3,4,2,1,5]
| 4	| [4, 4, 4, 4, 4] |	[4,1,2,3] | 
#### Trials & Solution
In order to calculate the failure rate of each stage, the number of players
who reach the stage and do not clear the stage are obtained by iterating the 
given `Stages` list. Further, divided-by-zero exception is considered when
calculating the failure rate. Sorting the stages is performed by `sort()` with 
lambda expression.

## 2019 Kakao Blind Recruitment: 무지의 먹방 라이브
#### Overview
Given `N` plates labeled from 1 to `N` in a rotating table, Muzi eats every plate
for a second. Each plate requires some seconds to be eaten up. It gives which
plate to eat after `K` second.
#### Example
| Plates | K | Answer |
|:------:|:- |:-------|
| [3, 1, 2] | 5 | 1 |

| Time(s) | Remaining Plates |
|:-------:|:----------------:|
|    0    |     [3, 1, 2]    |
|    1    |     [**2**, 1, 2]|
|    2    |     [2, **0**, 2]|
|    3    |     [2, 0, **1**]|
|    4    |     [**1**, 0, 1]|
|    5    |     [1, 0, **0**]|

After `K=5` seconds `[1, 0, 0]` is remaining. Therefore, the answer would be `1`.

#### Trials & Solution
First, considering this problem as a simple simulation, at each second, it
updates the remaining plates for `K` seconds. However, since given `K` is 
<img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;K\leq&space;2\cdot&space;10^{13}" title="\inline 1\leq K\leq 2\cdot 10^{13}" />, and `N` is <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N\leq&space;200,000" title="\inline 1\leq N\leq 200,000" />,
the naive approach, which takes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(KN)" title="\inline O(KN)" />,
is too slow.  
The plates are updated at every "remaining `N`" seconds. In fact, if there are `N`
plates remain, after `N` second, all plates are updated, meaning each time-to-eat
value of plates is decremented. Then, in the next iteration, again, 
time-to-eat values of each plate remaining are updated after `M` seconds.
Since the size of remaining plates can make it independent to the given `K`, the 
updating routine starts with the plate that has the least time-to-eat value.
If the current `K` can consume the least time-to-eat value, updating routine is
conducted; otherwise, the iteration stops, and the naive algorithrm is applied
with the remaining `K`. In conclusion, it takes `O(K)`.  

| K |  Remaining Plates: Time-to-eat value(Index)  | Computation |
|:-:|:------------------|:---------------------:|
| 5 | [1(2), 2(3), 3(1)] | (K=5) -= (Least=1) * (Size=3) |
| 2 | [**0**(2), **1**(3), **2**(1)] --> [1(3), 2(1)] | (K=3) -= (Least=1) * (Size=2)
| 0 | [**0**(3), **1**(1)] --> [1(1)] | DONE |

## 2019 Kakao Blind Recruitment: 매칭 점수
#### Overview
Given a list of HTML texts and a target word, it returns the page that has the 
highest "Matching score." Matching score is the sum of Base score and Link score.
* Base score of Page X: the frequency of target word(case-insensitive) in the 
text of the web page
* Link score of Page X: the sum of (Base score of pages that are linked toward
Page X) / (the number of pages that are out-wardly linked from Page X)
#### Example
<p align="center">
    <img src="https://grepp-programmers.s3.amazonaws.com/files/production/48a36ec7fa/243a621b-f823-4ccd-99f1-2d8d3e14050d.jpg">
</p>

```
Target Word: HI

Matching score of Page A = Base score of Page A + Link score of Page A = 1 + 5 = 6
    Base score of Page A = Frequency of the word, "HI", in the text = 1
    Page B and Page C are linked toward Page A.
    Link score of Page A =
        Base score of Page B / The number of out-wardly linked of Page B +
        Base score of Page C / The number of out-wardly linked of Page C
    =   4 / 2 + 9 / 3
    =   5
```

#### Trials & Solution
The key to solve this problem is to efficiently parse the target portion of string
out of the given string.
```
string parse(string page, string s_target, string e_target, size_t start = 0){
    size_t s_pos = page.find(s_target, start);
    s_pos += s_target.length();
    size_t e_pos = page.find(e_target, s_pos);
    
    return page.substr(s_pos, e_pos - s_pos);
}
```
The above `parse()` method extracts string in between the end of `s_target` and
the begging of `e_target`. For example, in order to parse the text of `<body>`
tag from the web page, `parse(page, "<body>", "</body>");` is called. Likewise,
it can parse all information required, such as the current URL, outward links, etc.

## 2021 Kakao Blind Recruitment: 신규 아이디 추천
#### Overview
Given a user-id, it appies the following seven steps to the given user-id:
* Step1: convert all characters into lowercases
* Step2: remove all characters other than alphabet, digit, dash(-), underscore(_), 
and period(.)
* Step3: replace consecutive periods with a period
* Step4: remove starting and ending period
* Step5: if the given user-id is empty, put "a"
* Step6: if the user-id is longer than 15 letters, truncate it up to 15 letters.
If the last letter of the truncated string is a period, remove it
* Step7: if the user-id is shorter than 3 letters, append the last character
until the length becomes 3.
#### Trials & Solution
Simple simulation problem. Initially, all the steps are implemented into one
method; however, it doesn't have any advantages in performance but reduces its
readability. Therefore, each step is implemented in a seperate function.

## 2022 Kakao Blind Recruitment: 신고 결과 받기
#### Overview
Given a user-reporting system and a log from it, it computes the number of 
reporting receipt for each user. The reporting system works as the following:
* Each user can reports a user at a time
    * Multiple reportings are allows
    * Duplicate reporting to the same user is counted as one reporting
* Users who get reported for more than and equal to `k` times get banned, and 
the reporters get the reporting receipt

#### Trials & Solution
Three `maps` are used:
* `index_map`: since the problem's output requires to remember the given order 
of users, it simply stores `ID: given index` data
* `num_reported`: stores `ID: #reported`
* `who_reported`: stores `ID: [reporters ...]`

Iterating the given log, first, the log is splited into `Report`, which consists 
of `reported` and `reporter`. Then, it checks if a report is a duplicate with `who_reported`.
If `who_reported[current reported]` contains `current reporter`, it is a duplicate 
therefore ignores this report; otherwise, it add this report information to the maps.
With the processed maps, it finds users who got >=`k` reports and sends the 
reporting receipts. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O((N&space;&plus;&space;M)logM)" title="\inline O((N + M)logM)" /> at the worst case 
where N is the number of reports, and M is the number of users.