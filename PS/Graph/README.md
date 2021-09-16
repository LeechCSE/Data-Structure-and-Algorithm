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
Given a N-by-M matrix with blocks that is not visitable and multiple starting
points, as adding three extra blocks, it gives the maximum number of unvisited
grids. It is a typical problem that requires BFS algorithm but an extra
restriction: the three extra blocks. Brute-force method is the only way, as 
there is no optimal solution for this case. For every possible map with the new
blocks, BFS algorithm is used; therefore, it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^4M^4)" title="\inline O(N^4M^4)" />, which is acceptable
for <img src="https://latex.codecogs.com/svg.image?\inline&space;3&space;\leq&space;N,&space;M\leq&space;8" title="\inline 3 \leq N, M\leq 8" />.

## BOJ#12886 돌 그룹
Given three groups of stones, it checks if the number of stones of each group
can be the same with the redistribution rule. Pick two groups of which number
of stones are different. Redistribute x stones of the group of higher number of
stones to the other. Again, it is a typical problem that requires brute-force
algorithm, specifically, BFS algorithm taking the number of stones for each
group as a node. However, as the number of groups are three, the space-complexity
of `visited` vector is <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^3)" title="\inline O(N^3)" /> wherer N is the maximum number of stones, which is
in this case about 1500. In order to resolve this issue, the node only takes
two groups, not three; then it becomes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^2)" title="\inline O(N^2)" />. Since it is 'redistribution', 
the total number of stones for all group remains the same; therefore, the third
group, which is not taken for the node, can be figured in run-time as well.

## BOJ#2206 벽 부수고 이동하기
Given an N-by-M matrix with zero as an accessible path and one as a inaccessible
wall, it gives the shortes path from (0, 0) to (N-1, M-1). A special restriction
in this problem is it is allowed to break a wall only once. Initially, the
brute-force method is applied by executing BFS algorithm for all possible
map that has one less wall from the given map; however, as it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^2M^2)" title="\inline O(N^2M^2)" />, it is not accepted for <img src="https://latex.codecogs.com/svg.image?\inline&space;1&space;\leq&space;N,&space;M\leq&space;1,000" title="\inline 1 \leq N, M\leq 1,000" />. In order to resolve this issue, the node of simulated graph is 
changed from a simple coordinate (y, x) to (y, x, broken) wherer `broken` 
represents whether or not it's broken once. By doing so, the time complexity
becomes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(NM)" title="\inline O(NM)" />.

## BOJ#16946 벽 부수고 이동하기 4
An N-by-M matrix with zero as an accessible path and one as a inaccessible
wall is given. Consider this matrix as a graph with grid as node and
adjacent grid as adjacent nodes connected by edges. It gives the number
of connected components for each sub-graph assuming that a wall is broken
so that it is accessible. Initially, the brute-force technique is applied.
For every wall, execute BFS algorithm to get the number of connected
components; it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^2M^2)" title="\inline O(N^2M^2)" />.
It is not acceptable for the given N and M where <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N,&space;M&space;\leq1,000" title="\inline 1\leq N, M \leq1,000" />.
The more efficient way only uses BFS algorithm, which is the bottle-neck,
once. First, in one iteration of BFS algorithm, obtain all the number of connected
components for given graph, not considering broken walls. Then, for every wall,
it checks if some commponents are adjacent. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(NM)" title="\inline O(NM)" />.

## BOJ#14442 벽 부수고 이동하기 2
Given an N-by-M matrix with zero as an accessible path and one as a inaccessible
wall, it gives the shortes path from (0, 0) to (N-1, M-1). An extra restriction
is that it is allowed to break up to K walls if it makes the path shorter.
BFS algorithm is used with the node consisting of `{y, x, num_broken}` information.
`y` and `x` represents the coordinate of the given matrix, and `num_broken`
indicates the number of walls  it has broken so far. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(NM)" title="\inline O(NM)" />.

## BOJ#16933 벽 부수고 이동하기 3
As with the previous problem, BOJ#14442, an N-by-M matrix with path and
wall and restriction of breaking up to K walls are given. In addition, 
an extra restriction of time is given. For every action, time goes from 
daytime to nighttime or vice versa. Breaking a wall can only be done
in daytime. In order to embrace the new restriction, a new member, `time`,
is added to the `Node`. Although space complexity increses, it still runs
at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(NM)" title="\inline O(NM)" />.

## BOJ#16954 움직이는 미로 탈출
Given an 8-by-8 maze, it checks if it can go from (7, 0) to (0, 7). Each
row of maze is moving downward for every move. If the wall is moved to
the current position, it's stuck. Since the maze is given with fixed size
of 8, the eight possible maps are generated initially. Then, using Node
of `{y, x,  map_id}`, BFS algorithm is used.

## BOJ#16236 아기 상어
An n-by-n matrix filled with a 0-9 digit per a grid is given. Taking 9
as a starting point with starting size of 2, the cursor is moving through
the grids with less than or equal to current size. The cursor is moving for
the closest target/grid of which value is less than the current size. If there 
are multiple candidates, it takes the matrix-wise smallest element. It stops
moving when there are no target anymore. Until the end, it gives the total
number of moves.  
`find_fish()` method calls BFS algorithm to get the shortest path from
the current position to the target, which runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^2)" title="\inline O(N^2)" />, and can be called
<img src="https://latex.codecogs.com/svg.image?\inline&space;N^2" title="\inline N^2" />
times in the worst case. Thererfore, this algorithm runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^4)" title="\inline O(N^4)" />.

## BOJ#6087 레이저 통신
Given an N-by-M matrix filled with `.` for an accessible path and `*` as a wall
and starting and end points, it gives the minimum number of mirrors required to 
connect the two given points with the laser. As the laser goes strainght,
only the mirror can change its direction.
```
Example of 8 x 7 Matrix:

. . . . . . .         . . . . . . .
. . . . . . C         . . . . . /-C
. . . . . . *         . . . . . | *
* * * * * . *         * * * * * | *
. . . . * . .         . . . . * | .
. . . . * . .         . . . . * | .
. C . . * . .         . C . . * | .
. . . . . . .         . \-------/ .
```
The above example shows that three mirrors(`/`or`\`) are required to connect
the two `C` points.  
As the problem is of the "minimum" thing, the BFS algorithm is used taking
each grid as a node, all adjacent nodes on the same straight lines as an edge,
and the number of straight lines needed as a weight of the edge.
```
Count map:

2 2 2 2 2 2 1
1 1 1 1 1 1 C  <-- Starting point
2 2 2 2 2 2 *
* * * * * 2 *
4 4 4 4 * 2 3
4 4 4 4 * 2 3
4 C 4 4 * 2 3
3 3 3 3 3 2 3
```
With the same example, the final `count map` would be the above. The four
straight lines are required to connect the two points; therefore, three 
mirrors are requried. As it is a simple BFS algorithm, it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(NM)" title="\inline O(NM)" />.

## BOJ#1963 소수 경로
Given two four-digit prime numbers, `start` and `end`, by changning one 
digit of `start` at a time, it gives the minimum number of changes to make 
`start` be `end`. The BFS algorithm is used with all prime numbers in range
as nodes. At every iteration, it checks the adjacent number is a prime
number; it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(m\sqrt{n})" title="\inline O(m\sqrt{n})" />.
where m is the number of digits of n.

## BOJ#10026 적록 색약
Given an N-by-N matrix filled with either `R`, `G`, or `B`, it gives the 
number of connected components. An extra restriction is that RG-color-weakness
cannot distinguish between `R` and `G`; therefore, `R` node and `G` node are
thought to be connected in this case. The BFS algorithm is used for both
case. In RG-color-weakness case, it simply changes `B` to `R`. It runs
at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(M\sqrt{N})" title="\inline O(M\sqrt{N})" />
where M is the number of digits of N.

## BOJ#14395 4연산
Given two number `s` and `t`, using arithmetic operations, `*`, `+`, `-`,
`/`, it gives the operations used to make `s` by `t` with the minimum
number of operations. As it is about the minimum stuff, the BFS algorithm
is used with all possible numbers that can be made from the operations.
It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N)" title="\inline O(N)" />
where <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N\leq&space;10^9" title="\inline 1\leq N\leq 10^9" />.
Although the input number can be way bigger than one billion, since the 
algorithm tries to reach the target, it doesn't probe that big number.

## BOJ#5014 스타트링크
Given N as the size of problem, starting and end point, and forward
and backward offsets, it gives the minimum number of steps from the start
to the end. The BFS algorithm is used with the current position as node
and the offset as edge; it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N)" title="\inline O(N)" />.

## BOJ#1600 말이 되고픈 원숭이
Given an N-by-M matrix and `k` that represents the limit of knight-like
moves, it gives the minimum number of moves from `(0, 0)` to `(N - 1, M - 1)`.
If the knight-like moves are used beyond the limit, the cursor moves in four
directions: left, right, up, and down. The BFS algorithm is used with node
of `{y, x, num_knights}` where `y` and `x` indicates the coordinates and
`num_knights` shows the number of knight-like moves used.