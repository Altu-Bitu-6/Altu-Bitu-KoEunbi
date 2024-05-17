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
		if (arr2[arr1[r]] < k) {  //현재 원소의 개수가 K 미만
			arr2[arr1[r++]]++; //오른쪽 포인터 이동
			ans = max(ans, r - l); //최댓값 갱신
		}
		else if (arr2[arr1[r]] == k) { //K개인경우
			arr2[arr1[l++]]--; //왼쪽 포인터 이동
		}
	}
	cout << ans;

	return 0;
}
