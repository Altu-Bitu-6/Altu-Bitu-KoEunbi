#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<char> s;
	string input;
	char c;

	while (1) {
		getline(cin, input); //���� ������ �Է�

		if (input[0] =='.')
			break;

		for (int i=0; i < input.size(); i++) {
			c = input[i];

			if (c == '(' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (s.empty()) {
					s.push(c);
					break;
				} else if (s.top() == '(')
					s.pop();
				else
					break;
			}
			else if (c == ']') {
				if (s.empty()) {
					s.push(c);
					break;
				}
				else if (s.top() == '[')
					s.pop();
				else
					break;
			}
		} //���ڿ� �˻�

		if (!s.empty()) {
			cout << "no\n";
			while(!s.empty())
				s.pop();
		}
		else
			cout << "yes\n";
	}

	return 0;
}