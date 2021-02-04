#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n, x[MAXN], y[MAXN];

/*
* If we number the points from 1 to N, and skip point K, then the path we take goes from point 1 to point K−1, 
* then from point K−1 to point K+1, and then from point K+1 to point N. The distance of this path is exactly equal to the following:

(total distance without skipping any points) - (distance between points K−1 and K) - (distance between points K and K+1) + (distance between points K−1 and K+1).

We can compute the value of A, B, C, D separately and find the minimum value of A-B-C+D, where
A = (total distance without skipping any points) 
B = (distance between points K−1 and K) 
C = (distance between points K and K+1) 
D = (distance between points K−1 and K+1).
*/

int main()
{
    // Read in data
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Compute A (Note that A is constant)
    int totalDistance = 0;
    for (int i = 1; i < n; i++) {
        totalDistance += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    }

    // Compute the maximum value of (B+C-D) with a picked skipping point K (1<K<n)
    // ---> will lead to minimum value of A-(B+C-D) = A-B-C+D = the answer
    int largestSkip = 0;
    for (int i = 1; i < n - 1; i++) {
        // Commpute B+C
        int noSkipDistance = abs(x[i + 1] - x[i]) + abs(x[i] - x[i - 1]) + abs(y[i + 1] - y[i]) + abs(y[i] - y[i - 1]);
        // Copute D
        int skipDistance = abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
        // Update current maximum of (B+C-D)
        largestSkip = max(largestSkip, noSkipDistance - skipDistance);
    }

    // The answer will be constant A - maximum of (B+C-D) = minumum of (A-B-C+D)
    cout << totalDistance - largestSkip;

    return 0;   
}


