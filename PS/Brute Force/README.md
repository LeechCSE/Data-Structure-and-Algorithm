# Problem Solving: Brute Force

## BOJ#6603 로또
#### Overview
Given a set `S` with `K` numbers, it gives the 6-combination of set `S`.
#### Trials
Instead of using recursion, `prev_permutation()` in `<algorithm>` library is used.
`prev_permutation()` and `next_permutation()` of a set give the permutation of the set.
In order to obtain the combination instead of permutaion, a helper vector of boolean values
is used. With the helper vector filled with 6 `True` and K - 6 `False`, the permutation
of the helper function masks the set `S`. In fact, it works like a bit-mask but in 
vector format.

## BOJ#1182 부분수열의 합
#### Overview
Given a set `S` with `N` integers and target number `target`, it gives the
number of subset of which elements are summed up to `target`. The empty set
is not considered.
#### Trials
A subset of a set `S` is a combination of `S`. In order to check the validity,
all possible subsets must be checked from 1-combination to N-combination.
Again, using `prev_permutation()` with mask of size 1 to N, all subsets are
obtained.

## BOJ#14225 부분수열의 합
#### Overview
Given a set `S`, it gives the smallest natural number that cannot be made
from the sum of subset of set `S`.
```
Given S = [5, 1, 2],

1 from subset s = [1]
2 from subset s = [2]
4 MISSING!
3 from subset s = [1, 2]
5 from subset s = [5]
6 from subset s = [5, 1]
7 from subset s = [5, 2]
8 from subset s = [5, 1, 2]

ANS: 4
```
#### Trials
The combination of set `S` with mask is the subsets of set `S`. Using 
`prev_permutation()`, the sum of subsets is obtained. One tricky part would
be the duplicated sum. Since the answer is obtained using back-tracking technique
at the end of the program, the duplicated sum would be a mess. Therefore, the sums
are stored in a set, which only holds unique values in a sorted order.

## BOJ#148888 연산자 끼워넣기
#### Overview
N natual numbers and N - 1 operatios(`+`, `-`, `x`, `÷`) are given. The order of 
N numbers is fixed, and operator precedence is ignored, meaning that the operators
are executed from the front to the end. It gives the maximum and minimum output.
#### Trials
Using `next_permutation()` in `<algorithm>` library, [N-1]-combination, which gives 
all possible arrangements of N - 1 operators, is obtained. Since operator precedence
is ignored in this problem, for each operator, the output is accumulated.

## BOJ#15658 연산자 끼워넣기 2
#### Overview
Given N natural numbers and at least N - 1 operators(`+`, `-`, `x`, `÷`), it
gives the maximum and minimum output. The operator precedence is ignored.
#### Challenges
Since the number of operators are more than or equal to N - 1, [N-1]-combination
is needed. Simulating `+` as 0, `-` as 1, `x` as 2, and `÷` as 3 with mask,
the [N-1]-combination is obtained. Then, the permutation of the combination is
applied to get the output. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(\binom{4N}{N-1}(N-1)!)&space;=&space;O(\frac{(4N)!}{(3N&plus;1)!})" title="\inline O(\binom{4N}{N-1}(N-1)!) = O(\frac{(4N)!}{(3N+1)!})" />, which is terrible at all. Since there are many duplicated 
arrangements of operators, memoization technique is used with `<map>`. It leads time complexity
to <img src="https://latex.codecogs.com/svg.image?\inline&space;O(4^{N-1}log(N-1))" title="\inline O(4^{N-1}log(N-1))" />. The time complexity of accessing element of map is <img src="https://latex.codecogs.com/svg.image?\inline&space;O(log(N-1))" title="\inline O(log(N-1))" />. Even with `<unordered_map>`, it 
takes <img src="https://latex.codecogs.com/svg.image?\inline&space;O(1)" title="\inline O(1)" /> in average
case and <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N)" title="\inline O(N)" /> in
the worst case; then it runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(4^{N-1})" title="\inline O(4^{N-1})" /> on average case and <img src="https://latex.codecogs.com/svg.image?\inline&space;O(4^{N-1}(N-1))" title="\inline O(4^{N-1}(N-1))" /> in the worst case.
#### Trials
In order to achieve solid <img src="https://latex.codecogs.com/svg.image?\inline&space;O(4^{N-1})" title="\inline O(4^{N-1})" />, recursion is used. Calculating operands with given operators, it passes the
remaining number of operators into the next function call. It removes the duplicated arrangement. 
In fact, it is a simple brute-force technique with no duplicates without using caching.

## BOJ#14500 테트로미노
#### Overview
Given an N-by-M matrix filled with integers representing scores, it gives the
maximum score when a tetromino is placed on the matrix. Tetromino can be rotated
and flipped.
#### Trials
<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/All_5_free_tetrominoes.svg/200px-All_5_free_tetrominoes.svg.png" />
</p>
Tetrominoes of shape `I`, `O`, `L`, and `S` can be probed in DFS manner. In fact, all blocks can be covered without turning back to the previous block. On the other side, `T` shape tetromino cannot be covered with DFS manner probing. Based on this observation, `T` shape tetromino is hard-coded, and DFS-like
probing is applied to the other four tetrominoes.

## BOJ#16197 두 동전
#### Overview
Given an N-by-M matrix filled with some `.` as an accessible path, some `#` as
a wall, and two `o` as a coin, it gives the minimum number of moves to make
only one coin goes out of the matrix.
#### Challenges
There are many restriction in this problem. First, in the matrix, `#` is not
accessible by any coins; they can only go through `.`grids. In addition, the
coins  are able to go out of the matrix; however, only one is allowed. The
maximum number of moves that is allowed is 10.
#### Trials
The solution is implemented in recursive manner. There are three base cases:
1. The number of moves exceeds 10 -- Fail!
2. Both coins go out of the matrix -- Fail again!
3. Only one coin goes out of the matrix, and the other stays in -- Valid

Each recursive function call passes the number of moves(`num_clicks`) so far
and the position of the two coins(`c1`, `c2`). Based on the `num_clicks`,
it clears the first base case, and `c1` and `c2` clear the second and third
base cases. Since the first and second bases are not valid, they return `-1`
representing a failure. Among the outputs from the third base case, it gives
the minimum number of moves.

## BOJ#16198 에너지 모으기
#### Overview
Given a list of number, `w`, and the precedure of gathering energy:
1. Pick `x`th element where <img src="https://latex.codecogs.com/svg.image?\inline&space;1&space;<&space;x&space;<&space;|w|" title="\inline 1 < x < |w|" />.
2. Remove `x`th element from `w`
3. Gather energy = `w[x-1] * w[x+1]`
4. Update the size of `w` by one less and label the remaining elements by updated order

#### Challenges
The given precedure requires the repeating job for smaller input where in this case it is `w`. As
gathering energy, `w` gets smaller and smaller until the size of `w` is 2. In order to this
repeating job, recursion is used with the input of `w`. Initially, the recursive function
strictly follows the given precedure; with passed vector `w`, for each `x`, which is from 
1 to `|w|-1`th element, call itself with updated vector without element `x`. However, in this
manner, the input of sub-problem is not protected. In fact, at each depth of function call, the input
must remains the same whatever happen in the lower depth.
#### Trials
In order to keep the input from being changed by the lower depth process, a temporary vector
that copies the input `w` and is passed into the lower depth process.

## BOJ#9663 N-Queen
#### Overview
Given `N` where <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N<&space;15" title="\inline 1\leq N< 15" />, it gives the number of arrangement of N queens in an N-by-N chess board without
conflicting each other.
#### Trials
The queen can move any number of grids horizontally, vertically, or digonally. First, considering
the column of the chess board, there must be one queen per column at most. Therefore, iterating each column, it calls itself if there is no conflict verticall and diagonally.

## BOJ#2580 Sudoku
#### Overview
It is Sudoku but special one that can be solved with back-tracking technique.  
For example,  
<img src="https://upload.acmicpc.net/508363ac-0289-4a92-a639-427b10d66633/-/preview/">  
Given the special sudoku puzzle, it gives a solution out of many.
#### Trials
As the problem speicifies it can be solved with back-tracking method, brute-force
with back-tracking technique is applied. Caching three vectors, it iterates all
girds of the puzzle. The followings are the two dimentional cache vectors:
1. `row_check[i][x]`: whether number `x` exists in row `i`
2. `col_check[i][x]`: whether number `x` exists in column `i`
3. `sqr_check[i][x]`: whether number `x` exists in square `i` where squares are
labeled in row-major order.