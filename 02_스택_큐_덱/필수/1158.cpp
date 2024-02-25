#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	int i, j;

	cin >> n >> m;
	queue<int> q;

	for (i = 0; i < n; i++) {
		q.push(i + 1);
	}

	cout << "<";
	while(q.empty() == 0) {
		for (i = 1; i < m; i++) {
			j = q.front();
			q.pop();
			q.push(j);
		}
		cout << q.front();
		
		if (q.size() == 1)
			cout << ">";
		else
			cout << ", ";

		q.pop();
	}

	return 0;
}