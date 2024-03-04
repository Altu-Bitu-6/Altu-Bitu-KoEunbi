#include <iostream>
#include <algorithm>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {
    int a, b;
    int c, d;
    int deno, num, gcd;

    cin >> a >> b;
    cin >> c >> d;

    gcd = getGcd(b, d);

    num = (d / gcd) * a + (b / gcd) * c;
    deno = b * d / getGcd(b, d);
    gcd = getGcd(deno, num);

    cout << num / gcd << " " << deno / gcd;

    return 0;
}