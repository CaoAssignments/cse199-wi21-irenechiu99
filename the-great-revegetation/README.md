
## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=916&lang=en

## Key Concepts
 - Data Structure: Array/Vector
 - Algorithm: Sort/Swap, Graph Coloring, Greedy

## Idea



## Run Time
The complexity is O(NM). 
We have i iterate through the color vector whose size is N 
and j iterate through the fav_1 and fav_2 whose size are both M.

We might prove that the complexity is close to linear apply Tarjan's amortized complexxity model, but we will lead the complexity as it was anyways.

There is another way to reduce the complexity: storing for each vertex the identities of the <= 3 adjacent vertices.
The run time will be reduced from O(NM) to O(N).
However, for the given constraints, this optimization is unnecessary.