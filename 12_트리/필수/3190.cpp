#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int arr[1000][1000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, l, ans, dir = 1;
    queue <pair<int, char>> t;
    deque <pair<int, int>> dq;

    cin >> n >> k;
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

    while (1) {
        ans++;
        int nx = dq.back().first + dy[dir];
        int ny = dq.back().second + dx[dir];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n || arr[nx][ny] == 1)
            break;

        if (arr[nx][ny] != 2) {
            arr[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }

        arr[nx][ny] = 1;
        dq.push_back({ nx, ny });

        if (ans == t.front().first) {
            char ch = t.front().second;
            if (ch == 'D')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
            t.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}