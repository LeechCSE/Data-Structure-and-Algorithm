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
14
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

## BOJ#17086 아기 상어 2
Given an N-by-M matrix filled with zero or one, it gives the shortest path
from each grid to 1's grid. For each grid, the BFS algorithm is used to find
the shortest path to the 1's grid. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^2M^2)" title="\inline O(N^2M^2)" />.

## BOJ#4991 로봇 청소기
#### Overview
Given an N-by-M matrix filled with `.` as path, `*` as target, `x` as inaccessible grid, and `o` as the starting point, it gives the minimum number of moves to reach all targets from the starting point when the cursor can moves into its adjacent grids. 
#### Challenges
The total number of moves is not simply the sum of the shortest paths between targets.
```
  0 1 2 3 4     Path1: (2, 2) --|1|--> (3, 2) --|3|--> (1, 3) --|2|--> (0, 4) --|4|--> (1, 1)
0 . . . . *     #Moves: 1 + 3 + 2 + 4 = 10
1 . * . * .     
2 . . o . .     Path2: (2, 2) --|1|--> (3, 2) --|3|--> (1, 1) --|2|--> (1, 3) --|2|--> (0, 4)
3 . . * . .     #Moves: 1 + 3 + 2 + 2 = 8
4 . . . . .     
```
In the above example, both paths take the shortest target at each stage; however, if there are multiple closest targets, the output is not deterministic.
#### Trials & Solution
The brute-force method is applied for all permutaion of targets. In fact, from the given starting point, all possible combinations of targets become the path. As every stage requries the BFS algorithm, it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;(T&space;*&space;T!)O(NM)" title="\inline (T * T!)O(NM)" /> where T is the number of targets. As the input is given as <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N,\&space;M\leq&space;20" title="\inline 1\leq N,\ M\leq 20" /> and <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;T\leq&space;10" title="\inline 1\leq T\leq 10" />, in the worst case, it takes ~2 minutes.   
In order to increase the efficiency, memoization technique is used. Since the position of targets and starting point is fixed, at each stage, the BFS algorithm is probing the same graph. By caching the number of moves to reach all positions from the starting point and targets, the duplicated probing is removed. Therefore, it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;(T&space;*&space;T!)O(1)" title="\inline (T * T!)O(1)" />.

## BOJ#2234 성곽
#### Overview
An N-by-M matrix with each grid filled 4-bit value in decimal format is given.
The 4-bit value represents the existence of wall on west, north, east, south
face respectively. The wall cannot be gone through. It gives the number of
connected components, the number of nodes in the biggest connected component, 
and the number of nodes in new biggest connected component when a wall is
removed.
#### Trials & Solution
Two different BFS algorithm is used. One is for mapping connected components
from the given matrix. In `connected_component` map structure,
`(connected_component#, #nodes)` is stored. The other BFS algorithm is for 
obtaining the adjacent connected components of each connected component.
Removing a wall means that combining two connected components; therefore, 
it can obtain the third answer.

## BOJ#12906 New Tower of Hanoi
#### Overview
Similar to Tower of Hanoi, there are three towers(`A`, `B`, `C`) and some
plates that are also labeled with `A`, `B`, or `C`. The objective of this
puzzle is to put all plates on the right tower; `A`-plate must be on the
`A`-tower, and so on. With this setting, the algorithm gives the minimum
number of moves to reach the end.
#### Challenges
There is no magic equation to obtain the answer, meaning that it requires
the brute-force technique. Since this puzzle is not linear type of problem, 
the BFS algorithm is used. The challenge is how to define the node and 
how to check visit.
#### Trials & Solution
The node is defined as `State` that is simply `vector<string>`.
```
State[0]: Tower A
   ㄴ plates on Tower A
State[1]: Tower B
   ㄴ plates on Tower C
State[2]: Tower C
   ㄴ plates on Tower C
```
The visit check is done with `map` with key of `string`. Initially, `State`
itself is used as key; however, it takes too much memory and too much time
to access hash map. Therefore, the key is changed to `string`.
```
string generate_key(State s){
	string key = "";
	
	for (auto t : s){
		key += t;
		key += ".";
	}
	
	return key;
}
```
As shown above, the key is `A-plates.B-plates.C-plates`. The period is a
delimiter to make each state unique.
```
State 1: AA B _ --> key: AAB
State 2: A  A B --> key: AAB
```
The above example shows the possible problem of using the key without the 
delimeter. Although `State 1` and `State 2` are obviously differenet, due to the
empty tower, the same keys are generated.
```
State 1: AA B _ --> key: AA.B..
State 2: A  A B --> key: A.A.B.
```
The above shows the use of the delimiter`"."`. It distinguishes the plates of
each tower.

## BOJ#17141 연구소 2
#### Overview
A number `M` as the number of starting points and an N-by-N matrix filled
with `0` as an accessible path, `1` as a wall, and `2` as a potential starting 
point are given. At t = 0s, from the starting points, viruses are placed.
At each second, the viruses are infected into 4-way direction(up, down, left, 
and right). The algorithm gives the minimum time taken to infect all accessible
paths.
#### Trials & Solution
Among a number of potential starting points(let's say there are `K` starting
points), `M` number of starting points are chosen using `prev_permutation()` 
with `mask`. In order to implement combination with `prev_permuation()` or
`next_permutation()`, which is for permutation as the name indicates, the 
`mask` is used. `mask` consists of `M` number of `1`s and `K-M` number of
`0`s and is premutated. Then, the `mask` is `&(operator AND)` with `K` 
starting points. It gives `M`-combination from `K`. With the chosen `M` 
starting points, the BFS algorithm is applied to obtain the minimum time.

## BOJ#17142 연구소 3
#### Overview
Similar to BOJ#17141, a number `M` as the number of starting points and an 
N-by-N matrix filled with `0` as an accessible path, `1` as a wall, and `2` 
as a potential starting point are given. However, in this problem, the
starting points that are not chosen are still on the matrix under `unactivated`
state. Reaching the unactivated virus, the virus makes it activated. The
moving mechanism is exactly the same as the above problem.
#### Trials & Solution
The small difference in the problem doesn't make changes in the source code.
The unactivated virus can be considered as an accessible path while the viruses
are spreading. At the end of spreading, the grids with unactivated virus are 
also considered as infected grid. In fact, if the end point of spreading is 
the grid of unactivated virus, it is not counted. The only change in code is 
to handle this special case.

## 2019 Kakao Blind Recruitment: 길 찾기 게임
#### Overview
<p align="center">
    <img width="35%" src="https://grepp-programmers.s3.amazonaws.com/files/production/dbb58728bd/a5371669-54d4-42a1-9e5e-7466f2d7b683.jpg">
    <img width="35%" src="https://grepp-programmers.s3.amazonaws.com/files/production/6bd8f6496a/50e1df20-5cb7-4846-86d6-2a2f1e70c5da.jpg">
</p>

Given indexed nodes represented in `(x, y)` coordinate, it construct a binary
search tree and gives preorder and postorder of nodes. All `x`-coordinates are
unique; however, `y`-coordinates aren't. `y`-coordinate represents the level of
tree, and `x`-coordinate acts as the key of tree, which determines whether
a node belongs to left or right sub-tree.

#### Trials & Solution
First, the given data is sorted by `y`-coordinates in decreasing order. Since
`insert_node()` method of the binary search tree doesn't care about the level of 
nodes. In fact, it determines whether the new node is in the left or right
sub-tree based on the key, `x`-coordinate in this case.   
Then, with the `Node` struct, the binary tree is made in recursive fashion by
`insert_node()` method.
```
struct Node{
    int data;
    int key;
    Node* left;
    Node* right;
    
    Node(int _data, int _key){
        data = _data;
        key = _key;
        left = nullptr;
        right = nullptr;
    }
};

...

Node* insert_node(Node* root, int data, int key){
    if (root == nullptr)
        return new Node(data, key);
    
    if (key < root->key)
        root->left = insert_node(root->left, data, key);
    else
        root->right = insert_node(root->right, data, key);
    
    return root;
}
```

## BOJ#14502 연구소
#### Overview
Given an N-by-N matrix filled with `0` as room, `1` as wall, and `2` as virus, 
it computes the number of uninfected grids setting three new walls in the empty 
rooms.
#### Trials & Solution
It is trivial to set three new walls in the given matrix: combination(`#rooms
Choose 3`). `prev_permutation()` with bit-mask is used to implement the combination.
With the chosen three walls, BFS algorithm is conducted to find the number of
safe grids. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^4M^4)" title="\inline O(N^4M^4)" />.