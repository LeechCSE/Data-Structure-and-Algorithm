# Problem Solving: Dynamic Programming

## Programmers 2017 카카오코드 예선 보행자천국
Given a m-by-n matrix of which element represents an intersection, it gives the 
number of possible paths from (0, 0) to (m - 1, n - 1) element. There are two 
restrictions. If the value of an element is 1, we cannot get through, and if it
is 2, the direction cannot be changed; going straight is the only choice for 
2-value intersection. Memoization technique is used in this case.  
The optimal solution: ![equation](https://bit.ly/38CMWKR)