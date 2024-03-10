#include <iostream>

using namespace std;

void findPrime(bool b[], int n) {
	for (int i = 2; i*i < n; i++) {
		for (int j = i* i; j < n; j += i) {
			b[j] = 1;
		}
	}
}

int main() {
	int input, error = 1;
	bool prime[1000000] = { 0, };
	findPrime(prime, 1000000);

	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> input;
		if (input == 0)
			break;

		for (int i = 3; i < input; i += 2) {

			if (prime[i] == 0 && prime[input - i] == 0) {
				error = 0;
				cout << input << " = " << i << " + " << input - i << '\n';
				break;
			}
		}

	}

	if (error == 1)
		cout << "Goldbach's conjecture is wrong. \n";


	return 0;
}