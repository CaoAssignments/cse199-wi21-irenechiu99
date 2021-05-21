#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool valid(long long left, long long days, long long m, long long x) {
    
    // Base case for recursion
    if (days <= 0 || left <= 0) {
        return left <= 0;
    }

    // Y = load paid that day. 
    // Left indicates N-G in the formula given by USACO. Calculate Y.
    long long y = left / x;

    // If Y <= M, Y is set to M. 
    // Determine if it's possible to repay the remaining loan by paying M per day.
    if (y <= m) {
        return days * m >= left;
    }

    // If Y > M. Compute the number of days that we give Y gallons of milk. (givey)
    long long end = y * x;
    long long givey = min((left - end) / y + 1, days);

    return valid(left - y * givey, days - givey, m, x);
}

int main() {
    long long n, k, m;
    cin >> n >> k >> m;

    // Binary search to find the largest X.
    long long lo = 1;
    long long hi = pow(10, 12);

    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (valid(n, k, m, mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", lo);
}
