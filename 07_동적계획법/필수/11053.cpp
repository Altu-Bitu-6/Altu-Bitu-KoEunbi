#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, i, j, ans = 1;

    cin >> n;
    vector <int> arr(n);
    vector <int> score(n, 1);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 1; i < n; i++) {
        for (j = i; j > -1; j--) {
            if (arr[i] > arr[j] && score[i] <= score[j]) {
                score[i] = score[j] + 1;
            }
        }
        if (score[i] > ans)
            ans = score[i];
    }

    cout << ans;

    return 0;
}