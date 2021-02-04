## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=189

## Key Concepts
 - Problem topics: Graph, Path
 - Data types and data structures: 2-d array
 - Problem-solving strategies: Recursion

## Run Time
The running time of the program is O(N ^ 2 ^ 2) = O(N ^ 4) where N is equal to the length and width of the 2-d array.
If we set the M as the number of cells (M = N ^ 2), we get O(M ^ 2). 

Explanation: In this program, we try out each cell as the starting cell of the path. 
With our temporary starting cell, we use recursion to compute the optimal path, wich leads to (O(M)).
There are M cells, so that we repeatedly try out the temporary starting cell for M times. 
Hence, the total run time for this program is O(M ^ 2) = O(N ^ 4).

## Other
There is a similar LC problem that use stack data structure to achieve O(N) in 1-d. 
Feel free to check it out through this website: https://leetcode.com/problems/longest-valid-parentheses/

The solution is included in this folder.

