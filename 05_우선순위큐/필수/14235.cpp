#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, input, num;
	priority_queue <int> pq;

	cin >> n;

	while (n--) {
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			num = input;
			while (num--) {
				cin >> input;
				pq.push(input);
			}
		}

	}


	return 0;
}
