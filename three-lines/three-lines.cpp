#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1001000;

pair<int, int> lis[MAXN];
map<int, int> cou;
int distinct;
int n;

// Increment variable distinct using count map
void inc(int x) {
	if (cou[x] == 0) {
		distinct++;
	}
	cou[x] = cou[x] + 1;
}

// Decrease variable distinct using count map
void dec(int x) {
	cou[x] = cou[x] - 1;
	if (cou[x] == 0) {
		distinct--;
	}
}

int moo() {
	// Sort list and re-intialize the count map
	sort(lis, lis + n);
	cou.clear();
	distinct = 0;

	/* First case: the points can all be covered by 3 horizontal lines
	*  Using the inc function to increase the variable distinct
	*  After iterating through the whole list, we get the number of distnct y values
	*/
	for (int i = 0; i < n; ++i) {
		inc(lis[i].second);
	}
	// Check if the cows can all be covered by 3 horizontal lines
	// which means the number of distnct y values is less than or equal to three
	if (distinct <= 3) return 1;

	/* Second case: the points can be covered by 2 horizontal lines and 1 vertical line
	* To test if 2 horizontal lines and 1 vertical line are sufficient, we sort the points on x, 
	* and for each distinct x coordinate, 
	* we temporarily remove all the points having that x coordinate and test if the number of distinct y coordinates drops to at most 2.
	*/
	int i = 0, i1 = 0;
	while (i < n) {
		while (i1 < n && lis[i].first == lis[i1].first) {
			i1++;
		}
		for (int i2 = i; i2 < i1; ++i2) {
			dec(lis[i2].second);
		}
		if (distinct <= 2)  return 1;
		for (int i2 = i; i2 < i1; ++i2) {
			inc(lis[i2].second);
		}
		i = i1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lis[i].first >> lis[i].second;
	}
	/* First round - check that if the set of pair corresponds to these two cases:
	*  1. the points can all be covered by 3 horizontal lines
	*  2. the points can be covered by 2 horizontal lines and 1 vertical line
	*/

	// Return "1" if the given data correspond to the requirements to form three lines
	if (moo()) {
		cout << "1";
	}
	else {
		/* Second round - check that if the set of pair corresponds to these two cases:
		*  1. the points can all be covered by 3 vertical lines
		*  2. the points can be covered by 2 vertical lines and 1 horizontal line
		*/

		// Acheiving the second round by swapping the x and y values and reuse the moo function
		for (int i = 0; i < n; ++i) {
			swap(lis[i].first, lis[i].second);
		}
		// Return "1" if the given data correspond to the requirements to form three lines
		if (moo()) {
			cout << "1";
		}
		// Return "0" if the given data does not correspond any requirements to form three lines
		else {
			cout << "0";
		}
	}
	return 0;
}