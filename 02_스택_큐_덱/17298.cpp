#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	stack <int> s;

	cin >> n;

	int arr[n];
	int result[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) {
			s.pop();
		}
		if (s.empty())
			result[i] = -1;
		else
			result[i] = s.top();

		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";

	return 0;
}