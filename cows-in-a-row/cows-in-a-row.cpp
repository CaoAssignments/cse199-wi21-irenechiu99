#include <iostream>
using namespace std;

int id[1005];

int get_largest_block(int n, int idignore) {
	int maxBlockSize = 0;
	int curBreed = -1;
	int curSize = 0;

	for (int i = 0; i < n; i++) {
		if (id[i] != idignore) {
			if (curBreed == id[i]) {
				// Extend the block if the current breeding ID is the same
				curSize++;
			}
			else {
				// Reset the current breeding ID if the breeding ID we get is neighther the idignore nor the current breeding ID
				curBreed = id[i];
				// Reset the current block size as well
				curSize = 1;
			}
			// Update the max block size if the block size we get is greater than the current max block size
			if (curSize > maxBlockSize)
				maxBlockSize = curSize;
		}
	}

	return maxBlockSize;
}

int main() {

	// Read in data
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// Find the maximum block size with the ignored breedID as id[i]
		int size = get_largest_block(n, id[i]);

		// Update the current answer if the maxmum block size if it is greater
		if (size > ans)
			ans = size;
	}
	cout << ans;
}