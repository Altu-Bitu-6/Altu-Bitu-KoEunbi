#include <iostream>

using namespace std;

int k;
int a[16];
int b[16];
int arr[4][2] = { {1,3}, {4,1}, {2,4}, {3,2} };

int cal() {
    for (int i = 0; i < 6; i++) {
        a[6 + i] = a[i];
        b[6 + i] = b[i];
    }

    int small = 0, big = 0;

    for (int i = 2; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] == arr[j][0] && a[i + 1] == arr[j][1]) {
                small = b[i] * b[i + 1];
                big = b[i - 2] * b[i + 3];
                return k * (big - small);
            }
        }
    }
}

int main() {
    int ans = -1;

    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> a[i] >> b[i];
    }

    ans = cal();
    cout << ans;

    return 0;
}