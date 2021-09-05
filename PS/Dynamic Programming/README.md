# Problem Solving: Dynamic Programming

## Programmers 2017 카카오코드 예선 보행자천국
Given a m-by-n matrix of which element represents an intersection, it gives the 
number of possible paths from (0, 0) to (m - 1, n - 1) element. There are two 
restrictions. If the value of an element is 1, we cannot get through, and if it
is 2, the direction cannot be changed; going straight is the only choice for 
value-2 intersection. Memoization technique is used in this case. The optimal solution:  
![equ1](https://latex.codecogs.com/svg.image?\theta_{ij}=\left\{\begin{matrix}\theta_{(i-1)j}\\\theta_{(i-x)j}\end{matrix}\right.&plus;\left\{\begin{matrix}\theta_{i(j-1)}\&space;where\&space;correspodint\&space;intersection\&space;value&space;=&space;0\&space;or\&space;1\\\theta_{i(j-y)}\&space;where\&space;corresponding\&space;intersection\&space;value&space;=&space;2\&space;\&space;\&space;\&space;\end{matrix}\right.\\\\_{\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;for\&space;smallest\&space;x\&space;s.t.\&space;2\&space;\leq\&space;x\&space;\leq\&space;i\&space;and\&space;intersection\&space;value_{(i-x)j}\&space;\neq\&space;2\&space;and}\\_{\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;\&space;for\&space;smallest\&space;y\&space;s.t.\&space;2\&space;\leq\&space;y\&space;\leq\&space;j\&space;and\&space;intersection\&space;value_{i(j-y)}\&space;\neq\&space;2})
