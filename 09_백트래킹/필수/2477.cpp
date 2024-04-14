#include <iostream>

#define SUM 1;
#define SUB 2;
#define MUL 3;
#define DIV 4;

using namespace std;



int main() {

	int n;
	vector <int> num;
	cin >> n;

	num.assign(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}


	return 0;
}