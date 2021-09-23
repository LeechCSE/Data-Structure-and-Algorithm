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