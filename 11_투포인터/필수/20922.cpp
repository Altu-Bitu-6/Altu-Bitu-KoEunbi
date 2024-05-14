#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr1[200000];
	int arr2[100000];
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
	}

	int ans = 0, l = 1, r = 1;

	while (l <= r && r <= n) {
		if (arr2[arr1[r]] < k) {
			arr2[arr1[r++]]++;
			ans = max(ans, r - l);
		}
		else if (arr2[arr1[r]] == k) {
			arr2[arr1[l++]]--;
		}
	}
	cout << ans;

	return 0;
}