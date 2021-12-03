# Problem Solving: Brute Force

## BOJ#6603 로또
#### Overview
Given a set `S` with `K` numbers, it gives the 6-combination of set `S`.
#### Trials & Solution
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
#### Trials & Solution
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
#### Trials & Solution
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
#### Trials & Solution
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
#### Trials & Solution
In order to achieve solid <img src="https://latex.codecogs.com/svg.image?\inline&space;O(4^{N-1})" title="\inline O(4^{N-1})" />, recursion is used. Calculating operands with given operators, it passes the
remaining number of operators into the next function call. It removes the duplicated arrangement. 
In fact, it is a simple brute-force technique with no duplicates without using caching.

## BOJ#14500 테트로미노
#### Overview
Given an N-by-M matrix filled with integers representing scores, it gives the
maximum score when a tetromino is placed on the matrix. Tetromino can be rotated
and flipped.
#### Trials & Solution
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
#### Trials & Solution
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
#### Trials & Solution
In order to keep the input from being changed by the lower depth process, a temporary vector
that copies the input `w` and is passed into the lower depth process.

## BOJ#9663 N-Queen
#### Overview
Given `N` where <img src="https://latex.codecogs.com/svg.image?\inline&space;1\leq&space;N<&space;15" title="\inline 1\leq N< 15" />, it gives the number of arrangement of N queens in an N-by-N chess board without
conflicting each other.
#### Trials & Solution
The queen can move any number of grids horizontally, vertically, or digonally. First, considering
the column of the chess board, there must be one queen per column at most. Therefore, iterating each column, it calls itself if there is no conflict verticall and diagonally.

## BOJ#2580 Sudoku
#### Overview
It is Sudoku but special one that can be solved with back-tracking technique.  
For example,  
<p align="center">
	<img src="https://upload.acmicpc.net/508363ac-0289-4a92-a639-427b10d66633/-/preview/">  
</p>
Given the special sudoku puzzle, it gives a solution out of many.
#### Trials & Solution
As the problem speicifies it can be solved with back-tracking method, brute-force
with back-tracking technique is applied. Caching three vectors, it iterates all
girds of the puzzle. The followings are the two dimentional cache vectors:
1. `row_check[i][x]`: whether number `x` exists in row `i`
2. `col_check[i][x]`: whether number `x` exists in column `i`
3. `sqr_check[i][x]`: whether number `x` exists in square `i` where squares are
labeled in row-major order.

## BOJ#3085 사탕 게임
#### Overview
Given an N-by-N matrix filled with a alphabet letter per grid, it gives
the longest common sub-sequence of row or column when swapping two
adjacent grids once.
```
  AAB   swapping (2, 1) and (2, 2)  AAB
  AAB   ==========================> AAB
  BBA                               BAB
  
(LCS: 2)                          (LCS: 3)
```
#### Trials & Solution
There is no special formula for figuring out the maximum LCS of swapping problem.
Thererfore, the brute-force technique is applied. For each element of the given
matrix, it swaps its adjacent element for four times(up, down, left, and right).
With the updated matrix with swapped elements, for each row and column, it 
obtains LCS and gives the maximum LCS out of them. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(N^4)" title="\inline O(N^4)" />. Some optimization could be applied.
First, since the swapping happens in row-major order, it doesn't need to check
all four directions. Only two directions(down and right) need to be checked.
In addition, since two elements are swapped at a time, LCS doesn't need to be run
for all rows and columns but either two rows or two columns depending on the direction
of swapping.

## BOJ#2529 부등호
#### Overview
Given `K` number of inequality symbols, it gives list of `K+1` numbers between 0 and
9 that meets the inequality symbols. Each number is used only once.
```
Given < and >,
0 < 2 > 1 
1 < 2 > 0 
    .
    .
    .
8 < 9 > 6 
7 < 9 > 8 
8 < 9 > 7
```
#### Trials & Solution
The problem can be easily reduced to a simple one. Among 0-9 numbers, choose
`K+1` numbers, <img src="https://latex.codecogs.com/svg.image?\inline&space;_{10}C_{k&plus;1}" title="\inline _{10}C_{k+1}" />, and since the order of `K+1` numbers matter, filter 
permutation of the `K+1` numbers with the given inequality symbols.

## 2017 카카오코드 본선: 단체사진 찍기
#### Overview
Given eight people(`A`, `C`, `F`, `J`, `M`, `N`, `R`, `T`} and a list of 
restrictions on arrangement of people in `X~Y=K`, `X~Y<K`, or `X~Y>K` format
where `X` and `Y` are from the given people and `K` is the number of other 
people in between `X` and `Y`. With this setting, it gives the number of 
cases of lining up the people under the restrictions.
#### Trials & Solution
Lining up eight people is a simple permutaion of them. The permutation is 
implemented with `next_permution()`. For each permuted arrangement, the 
restriction is tested. It runs at <img src="https://latex.codecogs.com/svg.image?\inline&space;O(8!*8N)" title="\inline O(8!*8N)" />.

## 2021 Kakao Blind Recruitment: 메뉴 리뉴얼
#### Overview
Given a list of strings `orders` of which element represents a set of individual
menus and a list of integers `course` that indicates the number of individual
menus for the course-menu to make, it gives the list of course-menu, which 
contains at least two individual menus ordered for the most among all orders 
that are ordered at least two times.
```
orders: "XYZ","WXY"    course: [2,3]

Size-2 course-menu candidates: "XY"(2 times), "XZ", "YZ", "WX", "WY"
==> "XY" is selected for the Size-2 course-menu
Size-3 course-menu candidates: "XYZ", "WXY"
==> None of them are qualified.

ANSWER: ["XY"]
```
#### Trials & Solution
Since there is no magic to check if the candidates are qualified, all cases
must be probed. For each order in `orders`, c-combination is required where
c is each and every element in `course`. The occurrance of c-combination
sub-string is counted to check its qualification for the course-menu.

## 2018 Kakao Blind Recruitment: 비밀지도
#### Overview
Two arrays of natural numbers are given. Each number in binary represent a map
consisting of walls and rooms; `1` indicates a wall, and `0` indicates a room. 
The secret map is the map made of the two given maps overlapped.
<p align="center">
    <img src="http://t1.kakaocdn.net/welcome2018/secret8.png">
</p>

#### Trials & Solution
"Overlapping" of binary numbers in this problem simply means `OR` operation. 
`bitset` datastructure is used to convert given `int` decimal to binary. One 
minor challenge of using `bitset` is that `bitset` cannot be initialized dynamically,
meaning that the size of `bitset` must be constant at the time of initialization.
Therefore, the maximum size of `N` is chosed. With the bitset data of two arrays,
`|(OR)` operation is applied.

## 2018 Kakao Blind Recruiment: 다트게임
#### Overview
Given the result of three shots in dart game in `Score|Bonus|[Option]` format,
it calculates the final score of the result. `Score` is inbetween 0-10. `Bonus`
is among `S`(single power), `D`(double power), and `T`(triple power). `Option`
is optional as the name indicates; it is either `*` or `#`. The option`*` means 
the previous and current score are doubled, and `#` leads to multiplying -1 to
the current score. Both option can exist in a game.
```
Result: 1D2S#3T*

1st shot: 1D  = 1^2                         =  1
2nd shot: 2S# = 2^1 * 2(from 3rd shot) * -1 = -4
3rd shot: 3T* = 3^3 * 2                     = 54

Final score: 1 - 4 + 54 = 51
```
#### Trials & Solution
Since there are only three shots, it manually iterates all shots with `id` backward.
The reason why it iterates backward is that the option `#` affects the previous
shot and `Score`, which is digit, always exists working as a delimiter of each
shot.

## 2018 Kakao Blind Recruitment: 캐시
#### Overview
With LRU(Least Recently Used) cache of `city`, given:
- a list of cities
- cache size: `N`
- cache hit cost: 1
- cache miss cost: 5

It caches cities in the given order.
#### Trials & Solution
In order to implement LRU cache machanism, `deque<string>` is used. `deque` allows
to access and modify both front and back element in <img src="https://latex.codecogs.com/svg.image?\inline&space;O(1)" title="\inline O(1)" />. 
In addition, it also supports iterator access; thererfore, it is easy to find 
and ultimately to modify a target.

## 2018 Kakao Blind Recruitment: N진법 게임
#### Overview
N-ary game is a game that `m` people say a single digit of `n`-ary numbers 
starting from 0. It gives `t` predictions as `p`th turn in the game.  

| n | t | m | p |
|:-:|:-:|:-:|:---|
| 2 | 4 | 2	| 1 |["09:10", "09:09", "08:00"] 

```
Binary(n = 2). 1th turn with 2 people in total. 4 predictions.
0, 1, 10, 11, 100, ...
--> 0 1 1 0 1 1 1 0 0...
    ^   ^   ^   ^
Predictions: 0111
```
#### Trials & Solution
The key of this problem is to convert decimal numbers into n-ary number. The
converted number is stored into `string` to break the "division" of numbers into
a single line of characters and to eventually access them easily.
