## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=916&lang=en

## Key Concepts
 - Problem topics: Graph
 - Data types and data structures: Path, 1-d array
 - Problem-solving strategies: Brute-Force, Greedy

## Run Time
The complexity is O(NM). 
We have i iterate through the color vector whose size is N. 
On top of that, for each i, we have j iterate through the fav_1 and fav_2 whose size are both M.

We might prove that the complexity is close to linear time by applying the Tarjan's amortized complexxity model, but the current complexity is efficient enough to pass the USACO test cases. 
[Reference](https://epubs.siam.org/doi/pdf/10.1137/0606031?casa_token=72mBETzNsVkAAAAA:cWFw5QX3lSuh6PK8A8pEWxnJV82s-prJcyMrp1BDsUL1gpqlY121Z6whPgMV4N8-yhDfW5BP2_4)

There is another way to reduce the complexity: storing for each vertex the identities of the <= 3 adjacent vertices.
The run time will be reduced from O(NM) to O(N).
However, with the data constraint, this optimization is unnecessary.