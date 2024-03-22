#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void push(priority_queue<char>& pq, string s) {
	for (int i = 0; i < s.size(); i++) {
		pq.push(s[i]);
	}
}

void check(priority_queue<char>& pq, int* arr) {
	int i, n = pq.size();

	for (i = 0; i < n; i++) {
		arr[pq.top() - 'A'] += 1;
		pq.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt, x, y, result = 0;
	int n1[26] = { 0, };
	int n2[26] = { 0, };
	string input;

	priority_queue<char> pq1;
	priority_queue<char> pq2;

	cin >> n;
	cin >> input;
	push(pq1, input);
	check(pq1, n1);

	n--;

	while (n--) {
		cnt = 0, x = 0, y = 0;
		memset(n2, 0, sizeof(n2));

		cin >> input;
		push(pq2, input);
		check(pq2, n2);

		for (int i = 0; i < 26; i++) {
			if (n1[i] == n2[i]) {
				continue;
			}
			if (abs(n1[i] - n2[i]) > 1) {
				cnt++;
				break;
			}
			else if (n1[i] > n2[i]) {
				x++;
			}
			else if (n1[i] < n2[i]) {
				y++;
			}

			if (x > 1 || y > 1) {
				cnt++;
				break;
			}
		}
		if (cnt > 0)
			continue;

		result++;


	}

	cout << result << '\n';


	return 0;
}