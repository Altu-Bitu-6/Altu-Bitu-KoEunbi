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

	int n, input, mid;
	cin >> n;

	priority_queue <int> small;
	priority_queue<int, vector<int>, cmp> big;

	while (n--) {
		cin >> input;

		if (small.empty() || input <= small.top())
			small.push(input);
		else
			big.push(input);

		if (small.size() > big.size() + 1) {
			big.push(small.top());
			small.pop();
		}
		else if (big.size() > small.size()) {
			small.push(big.top());
			big.pop();
		}

		cout << small.top() << '\n';
	}

	return 0;
}