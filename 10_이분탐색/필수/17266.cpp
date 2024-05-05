#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    int i, ans = 0;

    cin >> n;
    vector <int> road(n, 0);

    cin >> m;
    vector <int> light(m); 

    for (i = 0; i < m; i++) {
        cin >> light[i]; //가로등 위치 입력받기

        if (m == 1) { //가로등이 1개일 경우
            ans = (n - light[0] > light[0]) ? n - light[0] : light[0]; //양 끝단에서 더 긴 길이가 답
        }
        else if (i > 0 && (light[i] - (light[i] + light[i - 1]) / 2) > ans) //현재 입력받은 가로등과 지난 가로등의 거리가 기존 답보다 길 경우
            ans = light[i] - (light[i] + light[i - 1]) / 2; //ans값 업데이트
        else if (i == 0) //초기 상태에서 ans값 초기화
            ans = light[0];

    }
    if (n - light[m - 1] > ans) //마지막 가로등과 길끝의 거리가 기존 답보다 길 경우 업데이트
        ans = n - light[m - 1];

    cout << ans;

}
