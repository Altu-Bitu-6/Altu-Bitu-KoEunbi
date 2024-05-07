#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long binarySearch(long long n, long long m, vector <long long>& check_point) {
    long long l = 1, r = check_point[n - 1] * m; //r:가장 긴 시간의 경우

    long long mid, sum, ans = r;

    while (l <= r) {
        mid = (l + r) / 2; //걸리는 시간의 추정치
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mid / check_point[i]; //각 심사대에서 받는 사람의 수 누적합
            if (sum > m) //오버풀로우 방지
                break;
        }

        if (sum >= m) { //사람이 너무 많거나 같으면 -> 시간 줄이기 
            ans = mid;
            r = mid - 1;
        }
        else { //사람이 적으면 -> 시간 늘이기
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
