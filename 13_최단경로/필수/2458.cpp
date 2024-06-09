#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int map[1000][1000];
    int N, M, x, y, ans = 0;
    bool flag = true;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 9999999;
        }
    } //모든 경로를 초기화

    for (int i = 1; i <= N; i++) {
        map[i][i] = 0;
    } //자기 자신으로의 경로는 0

    for (int i = 0; i < M; i++) {
        cin >> x >> y; // x<y
        map[x][y] = 1;// x->y 경로를 1로
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            } //i->j 경로, i->k->j경로 중 더 짧은 경로 선택
        }
    }

    for (int i = 1; i <= N; i++) {
        flag = true;
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 9999999 && map[j][i] == 9999999) {
                flag = false; //알 수 없으니 빠져나오기
                break;
            }
        }
        if (flag)
            ans++; //알 수 있으면 증가
    }

    cout << ans;

    return 0;
}