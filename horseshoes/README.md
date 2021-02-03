## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=189

## Key Concepts
 - Problem topics: Graph, Path
 - Data types and data structures: 2-d array
 - Problem-solving strategies: Recursion

## Run Time
The running time of the program is O(N^2^2) = O(N^4) where N is equal to the length/width of the 2-d array.
If we set the M as the number of cells (M = N^2), we get O(M^2). 
In this program, we try out each cell start of the path. 
After we have our current starting cell, we use recursion to try out the optimal path (O(M)).
Hence we get worst case complexity O(M^2) which equals to O(N^4).

## Other
There is a similar LC problem that use stack data structure to achieve O(N) in 1-d. 
Feel free to check it out through this website: https://leetcode.com/problems/longest-valid-parentheses/

The solution is included in this folder.

