#include <iostream>
#include <vector>

using namespace std;

int cmp(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, i;
    bool flag = true;

    cin >> n;
    vector <int> arr(n);
    vector <int> score(n);


    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    score[0] = arr[0];

    if (n > 1) {
        score[1] = arr[0] + arr[1];
    }
    if (n > 2) {
        score[2] = cmp(arr[0] + arr[2], arr[1] + arr[2]);
    }
    for (i = 3; i < n; i++) {
        score[i] = cmp(score[i - 2] + arr[i], score[i - 3] + arr[i - 1] + arr[i]);
    }

    cout << score[n - 1];


    return 0;
}