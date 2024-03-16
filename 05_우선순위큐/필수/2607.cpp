#include <iostream>
#include <queue>

using namespace std;
struct cmp {
	bool operator()(string a, string b) {
		return a < b; //오름차순

		if()

	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string input;
	priority_queue<string, vector<string>, cmp> pq;
	priority_queue<char> pq1;
	priority_queue<char> pq2;

	cin >> n;
	cin >> input;

	pq1.push(input);
	n--;

	while (n--) {
		cin >> input;
		pq2.push(input);
		cout >> pq2.top();
		pq2.pop();

	}


	return 0;
}