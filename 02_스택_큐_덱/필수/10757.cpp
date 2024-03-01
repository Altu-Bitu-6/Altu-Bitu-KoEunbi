#include <iostream>
#include <stack>

using namespace std;

void input(stack <int>* s) {
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		s->push(input[i]-'0');
	}
}

void calc(stack<int>& s1, stack<int>& s2, stack<int>& result) {
	int n = 0;
	
	while (!s1.empty() || !s2.empty() || n) {
		int sum = n;

		if (!s1.empty()) {
			sum += s1.top();
			s1.pop();
		}
		if (!s2.empty()) {
			sum += s2.top();
			s2.pop();
		}

		result.push(sum % 10);
		n = sum / 10;
	}
}

int main() {
	int n;
	stack <int> result;
	stack <int> s1;
	stack <int> s2;

	input(&s1);
	input(&s2);

	calc(s1, s2, result);

	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	
	return 0;
}