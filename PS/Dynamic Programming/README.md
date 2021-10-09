# Problem Solving: Dynamic Programming

## Programmers 2017 카카오코드 예선 보행자천국
#### Overview
Given a m-by-n matrix of which element represents an intersection, it gives the 
number of possible paths from (0, 0) to (m - 1, n - 1) element. There are two 
restrictions. If the value of an element is 1, we cannot get through, and if it
is 2, the direction cannot be changed; going straight is the only choice for 
value-2 intersection. Memoization technique is used in this case.  
#### Optimal solution
<p align="center">
    <img width="65%" src="https://latex.codecogs.com/svg.image?\theta_{ij}=\left\{\begin{matrix}\theta_{(i-1)j}\\\theta_{(i-x)j}\end{matrix}\right.&plus;\left\{\begin{matrix}\theta_{i(j-1)}\&space;where\&space;corresponding\&space;intersection\&space;value&space;=&space;0\&space;or\&space;1\\\theta_{i(j-y)}\&space;where\&space;corresponding\&space;intersection\&space;value&space;=&space;2\&space;\&space;\&space;\&space;\end{matrix}\right.\\\\_{\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;for\&space;smallest\&space;x\&space;s.t.\&space;2\&space;\leq\&space;x\&space;\leq\&space;i\&space;and\&space;intersection\&space;value_{(i-x)j}\&space;\neq\&space;2\&space;and}\\_{\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;for\&space;smallest\&space;y\&space;s.t.\&space;2\&space;\leq\&space;y\&space;\leq\&space;j\&space;and\&space;intersection\&space;value_{i(j-y)}\&space;\neq\&space;2}" title="\theta_{ij}=\left\{\begin{matrix}\theta_{(i-1)j}\\\theta_{(i-x)j}\end{matrix}\right.+\left\{\begin{matrix}\theta_{i(j-1)}\ where\ correspodint\ intersection\ value = 0\ or\ 1\\\theta_{i(j-y)}\ where\ corresponding\ intersection\ value = 2\ \ \ \ \end{matrix}\right.\\\\_{\ \ \ \ \ \ \ \ \ \ \ \ \ \ for\ smallest\ x\ s.t.\ 2\ \leq\ x\ \leq\ i\ and\ intersection\ value_{(i-x)j}\ \neq\ 2\ and}\\_{\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ for\ smallest\ y\ s.t.\ 2\ \leq\ y\ \leq\ j\ and\ intersection\ value_{i(j-y)}\ \neq\ 2}" />
</p>

## BOJ#11048 이동하기
#### Overview
Given an N-by-M matrix(`A[*][*]`) filled with natural numbers, it gives the 
maximum summation of the natural numbers moving from `(1, 1)` to `(N, M)` if 
`(i, j) --> (i+1, j), (i, j+1), or (i+1, j+1)` are allowed.
#### Optimal solution
<p align="center">
    <img width="45%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_{ij}:&space;the\&space;maximum\&space;summation\&space;upto\&space;(i,&space;j)" title="\inline \theta_{ij}: the\ maximum\ summation\ upto\ (i, j)" />
<br/ >
    <img width="45%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_{ij}=max(\theta_{(i-1)j},\&space;\theta_{i(j-1)},\&space;\theta_{(i-1)(j-1)})\&space;&plus;\&space;A_{ij}" title="\inline \theta_{ij}=max(\theta_{(i-1)j},\ \theta_{i(j-1)},\ \theta_{(i-1)(j-1)})\ +\ A_{ij}" />
<br/ >
    <img width="25%" src="https://latex.codecogs.com/svg.image?\inline&space;(2\leq&space;i\leq&space;N,\&space;2\leq&space;j\leq&space;M,\&space;\theta_{11}=A_{11})" title="\inline (2\leq i\leq N,\ 2\leq j\leq M,\ \theta_{11}=A_{11})" />
</p>

## BOJ#11060 점프 점프
#### Overview
Given a 1-by-N matrix filled with an integer that represents the maximum number
of grids per jump, it gives the minimum number of jumps to reach `(0, N-1)` from 
`(0, 0)`.
#### Optimal Solution
<p align="center">
    <img width="51%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_i:&space;the\&space;minimum\&space;number\&space;of\&space;jumps\&space;up\&space;to\&space;i^{th}\&space;grid" title="\inline \theta_i: the\ minimum\ number\ of\ jumps\ up\ to\ i^{th}\ grid" />
<br/ >
    <img width="51%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_i&space;=&space;min\&space;\theta_x&space;&plus;&space;1\&space;&space;where\&space;0\leq&space;x&space;\leq&space;(i-1)\&space;and\&space;x&plus;A_x\geq&space;i" title="\inline \theta_i = min\ \theta_x + 1\ where\ 0\leq x \leq (i-1)\ and\ x+A_x\geq i" />
</p>

## BOJ#10942 Palindrome?
#### Overview
Given a list `A[]` consisting of `N` natural numbers and `M` queries in `(S, E)`
format, it gives the list `{A[S], A[S+1], ..., A[E-1], A[E]}` is palindrome.
#### Challenges
Checking a list of `N` number is palindrome or not takes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N)" title="\inline O(N)" />. Therefore, answering `M` queries
takes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(MN)" title="\inline O(MN)" />.
Another way of solving of this problem is to apply dynammic programming. By
using the symmetric characteristic of palindrome, the whole problem can be
divided into smaller sub-problems of which solution is also applied into the
other sub-problems, the other larger sub-problems, and even the whole problem.
#### Optimal Solution
<p align="center">
    <img width="45%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_{ij}:whether\&space;[A_i,&space;A_{i&plus;1},&space;...,&space;A_{j-1},&space;A_j]\&space;is\&space;palindrome" title="\inline \theta_{ij}:whether\ [A_i, A_{i+1}, ..., A_{j-1}, A_j]\ is\ palindrome" />
<br/ >
    <img width="25%" src="https://latex.codecogs.com/svg.image?\inline&space;\theta_{ij}=\theta_{(i-1)(j-1)}\&space;\bigcap\&space;(A_i=A_j)" title="\inline \theta_{ij}=\theta_{(i-1)(j-1)}\ \bigcap\ (A_i=A_j)" />
</p>