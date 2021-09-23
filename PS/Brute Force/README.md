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