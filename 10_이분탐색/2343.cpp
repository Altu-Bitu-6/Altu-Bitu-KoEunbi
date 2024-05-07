#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binarySearch(int n, int m, vector <int>& v) {
    int l = 1, r = 0;
    int mid, cnt, temp, size = 0;

    for (int i = 0; i < v.size(); i++) {
        r += v[i];
    }

    while (l <= r) {
        mid = (l + r) / 2;
        cnt = 0;
        temp = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] > mid) {
                cnt = m + 1;
                break;
            }

            temp += v[i];

            if (temp > mid) {
                cnt++;
                temp = v[i];
            }
            if (i == n - 1)
                cnt++;
        }

        if (cnt > m) {
            l = mid + 1;
        }
        else if (cnt <= m) {
            r = mid - 1;
            size = mid;
        }

    }

    return size;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n >> m;

    vector <int> lessons(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
    }

    cout << binarySearch(n, m, lessons);
}