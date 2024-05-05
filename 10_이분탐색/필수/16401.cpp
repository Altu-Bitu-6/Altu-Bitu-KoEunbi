#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binarySearch(int n, int m, vector <int>& v) {
    int l = 1, r = v[v.size() - 1];
    int mid, cnt, size;

    while (l <= r) {
        mid = (l + r) / 2;
        cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += v[i] / mid;
        }
        if (cnt >= m) {
            l = mid + 1;
            size = mid;
        }
        else if (cnt < m) {
            r = mid - 1;
        }
    }

    return size;
}
int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int cou, s, flag = 0, ans = 0;
    cin >> cou >> s;

    vector <int> snaks(s);
    for (int i = 0; i < s; i++) {
        cin >> snaks[i];
    }

    sort(snaks.begin(), snaks.end());

    cout << binarySearch(s, cou, snaks);

}