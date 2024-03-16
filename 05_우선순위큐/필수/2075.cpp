#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, input;
	priority_queue<int, vector<int>, cmp> pq;

	cin >> n;

	for (int i = n * n; i > 0; i--) {
		cin >> input;

		pq.push(input);

		if (pq.size() > n)
			pq.pop();

	}

	cout << pq.top() << '\n';



	return 0;
}