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