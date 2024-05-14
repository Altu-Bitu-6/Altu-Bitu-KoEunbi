#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d, k, c;
    int ans = 0, cnt=0;
    cin >> n >> d >> k >> c;
    vector <int> plate(n);
    bool plate_check[4000]; 

    for (int i = 0; i < n; i++) {
        cin >> plate[i];
    }

    for (int i = 0; i < n; i++) {
        cnt = 0;

        for (int j = i; j < i + k; j++) { //i부터 k개 접시 검사
            if (!plate_check[plate[j % n]]) {
                plate_check[plate[j % n]] = true;
                cnt++;
            }
        }

        if (!plate_check[c])//쿠폰초밥을 아직 안먹었으면 
            cnt++;

        ans = max(ans, cnt); //최댓값 갱신
        memset(plate_check, false, sizeof(plate_check));
    }

    cout << ans;

    return 0;
}
