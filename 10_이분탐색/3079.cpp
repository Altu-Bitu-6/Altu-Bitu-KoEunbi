#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long binarySearch(long long n, long long m, vector <long long>& check_point) {
    long long l = 1, r = check_point[n - 1] * m;

    long long mid, sum, ans = r;

    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mid / check_point[i];
            if (sum > m) //오버플로우 방지
                break;
        }

        if (sum >= m) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }

    }
    return ans;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    long long n, m;
    cin >> n >> m;

    vector <long long> check_point(n);
    for (long long i = 0; i < n; i++) {
        cin >> check_point[i];
    }

    sort(check_point.begin(), check_point.end());

    cout << binarySearch(n, m, check_point);

}