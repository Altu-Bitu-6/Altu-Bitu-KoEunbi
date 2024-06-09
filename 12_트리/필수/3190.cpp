#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int arr[1000][1000]; //게임 보드
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, l, ans, dir = 1;
    queue <pair<int, char>> t;
    deque <pair<int, int>> dq;

    cin >> n >> k;

    //위치 입력받기
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 2; 
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int N;
        char C;

        cin >> N >> C;
        t.push({ N, C });
    }

    arr[1][1] = 1;
    dq.push_back({ 1, 1 });

    while (1) { //게임 루프
        ans++;
        int nx = dq.back().first + dy[dir];
        int ny = dq.back().second + dx[dir];
        //다음 이동할 위치
        
        if (nx <= 0 || nx > n || ny <= 0 || ny > n || arr[nx][ny] == 1)
            break; //부딪히면 게임 종료

        if (arr[nx][ny] != 2) {
            arr[dq.front().first][dq.front().second] = 0;
            dq.pop_front(); //꼬리 제거
        }

        arr[nx][ny] = 1;
        dq.push_back({ nx, ny }); //새로운 위치 추가

        if (ans == t.front().first) {
            char ch = t.front().second;
            if (ch == 'D') //오른쪽으로 회전
                dir = (dir + 1) % 4;
            else //왼쪽으로 회전
                dir = (dir + 3) % 4;
            t.pop();
        }
    }
    //게임 끝난 시간 출력
    cout << ans << "\n";

    return 0;
}
