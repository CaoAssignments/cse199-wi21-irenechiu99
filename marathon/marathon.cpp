#include<iostream>
#define N 101000
using namespace std;

using namespace std;
long long n, m = 2000000000;
long long p[N], s[N];


int main() {
	cin >> n;
	int i;
	for (i = 1; i <= n; i++) {
		int t_p, t_s;
		cin >> t_p >> t_s;
		*(p + i) = t_p;
		*(s + i) = t_s;
	}
	int ans = 0;
	for (i = n; i; i--) {
		int now = i;
		ans++;
		while (i && (s[i - 1] - s[now]) * m >= (p[now] - p[i - 1]))i--;
	}
	cout << ans;
	return 0;
}