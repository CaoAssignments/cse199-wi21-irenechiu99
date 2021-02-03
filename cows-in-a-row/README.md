## Description
http://www.usaco.org/index.php?page=viewproblem2&cpid=130

## Key Concepts
 - Problem topics: Interval
 - Data types and data structures: 1-d array, 
 - Problem-solving strategies: Brute-force


## Run Time
We are using brute force to solve this problem. 
We iterate the array to try out the current breeding ID as the ignored breeding ID.
While trying out the ignored breeding ID, we need to iterate the array again 
and keep track the black size and find its maximum.

Hence, the running time of this algorithm is O(N^2).

Even though we are able to achieve O(N) running time by modifying our program,
we can leave it like this because of the restriction of given data.
