## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=509

## Key Concepts
 - Problem topics: Algebra
 - Data types and data structures: String
 - Problem-solving strategies: Brute-Force


## Run Time
The input file starts with an integer K, then it contains K lines each
specifying a separate test case. Each test case consists of two
3-digit numbers.  The first is a number N written in base X, and the
second is N written in base Y (N, X, and Y are possibly different for
each test case). We also know that both X and Y are in the range 10..15,000.

We use brute-force to solve this problem by trying out differnt X and Y by 
incrementing the smaller one until both base X and base Y yield the same value.

While calculating the result for each line of test case, we get the run time O(M^2) where M is in the range 10..15,000.
The total number of test cases is K, so that we get O(K * M ^ 2)
for this program.
