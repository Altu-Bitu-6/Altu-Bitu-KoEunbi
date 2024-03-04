#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int size, cnt;
	int s, idx = 0;
	char c;

	cin >> size >> cnt;

	vector<char> arr(size, '?');

	while (cnt) {
		cin >> s >> c;
		idx = (idx + s) % size;
		if (arr[idx] != c && find(arr.begin(), arr.end(), c) != arr.end()) {
			cout << "!";
			return 0;
		}
		if (arr[idx] != '?' && arr[idx] != c) {
			cout << "!";
			return 0;
		}

		arr[idx] = c;
		cnt--;
	}

	for (cnt = 0; cnt < size; cnt++) {
		cout << arr[idx];
		idx = (size + idx - 1) % size;
	}

	return 0;
}