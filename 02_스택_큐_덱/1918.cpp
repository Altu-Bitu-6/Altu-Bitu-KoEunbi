#include <iostream>
#include <stack>

using namespace std;

int main() {
	char c;
	string input;
	stack <char> s;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		c = input[i];

		if (c == '+' || c == '-') {
			while (!s.empty()&&(s.top() == '*' || s.top() == '/'||s.top() == '+' || s.top() == '-')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '*' || c == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '(') {
			s.push(c);
		}
		else if (c == ')') {
			while (!s.empty()&&s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << c;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}