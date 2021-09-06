# Problem Solving: Graph

## BOJ#12946 육각 보드
 Given slots to color in a hexagonal board, it gives the number of colors to
 color all given slots. The adjacent slots cannot have the same color. In 
 general, the graph coloring problem is NP-complete, which means that it can be 
 solved only with the brute-force manner. However, in this case of hexagonal 
 board, the possible solutions are 0, 1, 2, or 3. If there is no valid slot, 
 the number of color is 0 obviously. If there are only slots that all don't 
 have adjancet slots, the answer is 1. Choosing between 2 and 3 can be done by 
 using bipartite algorithm. If all the given connected components are 
 bipartite, the answer is 2; otherwise, the answer is 3. This idea is obtainned 
 by observation.

## BOJ#1707 이분 그래프
Given a graph, it checks if the graph is bipartite or not. First, using DFS 
algorithm(recursive version), it colors the nodes with two colors. 
Specifically, a color is used for a node, and then the other color is used for 
its adjacent nodes. Then, with the colored graph, it checks whether the 
adjacent nodes have the same color.

## Programmers 2017 카카오코드 예선 컬러링북
Given a m-by-n matrix, it gives the number of components distinguished by 
the value of matrix and the number of nodes for the largest connected component.
Considering each element of the matrix as a node of a graph, BFS algorithm is
used for each connected component.

## BOJ#16928 뱀과 사다리 게임
Snakes and Ladders is a board game. With a numbered board from 1 to n, some 
snakes and ladders are given connecting i th grid to j th grid. A ladder
connects from lower grid to higher grid, and the snakes works oppositely. For 
each turn, a dice is rolled to move grids. The objective is to reach the 
end-grid.  
Given the above rule of the game, the algorithm gives the smallest number of
rolls to reach the end. The algorithm simulates the board as a vector containing
0 or x value. In fact, if there is no snake nor ladder, the value of an element 
is 0; otherwise, the value is the destination of the snake or ladder. Using BFS 
algorithm, it counts the number of rolls. Due to the characteristic of BFS
algorithm, it gives the smallest one among the all possible ways.

## BOJ#16948 데스 나이트
Given a new chess knight that can moves to six possible ways and starting and 
end point, it gives the minimum number of moves to reach the end from the start.
As it's of the shortest path, BFS algorithm is used.

## BOJ#14502 연구소
Given a n-by-m matrix with blocks that is not visitable and multiple starting
points, as adding three extra blocks, it gives the maximum number of unvisited
grids. It is a typical problem that requires BFS algorithm but an extra
restriction: the three extra blocks. Brute-force method is the only way, as 
there is no optimal solution for this case. For every possible map with the new
blocks, BFS algorithm is used; therefore, it runs at O((NM)^4).