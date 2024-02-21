#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpAdv(string& s1, string& s2) {
	int num1 = 0, num2 = 0;

	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				num1 += s1[i] - '0';
			}
			if (s2[i] >= '0' && s2[i] <= '9') {
				num2 += s2[i] - '0';
			}
		}
		if (num1 == num2) {
			for (int i = 0; i < s1.size(); i++) {
				if (s1[i] == s2[i])
					continue;
				else
					return s1[i] < s2[i];
			}
		}
		return num1 < num2;
	}
	return s1.size() < s2.size();
}

int main() {
	int n;
	cin >> n;

	string arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmpAdv);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}