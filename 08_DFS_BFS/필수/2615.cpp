#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 21;
int x2, y2, mx[] = { -1, 0, 1,1 }, my[] = { 1,1,1,0 };
vector<vector<int>> map;
vector <vector<bool>> visited_map;

void bfs(int x, int y, int x_start, int y_start, int n, int dir) {
    visited_map[x][y] = true;

    for (int i = 0; i < 4; i++) {
        x2 = x + mx[i];
        y2 = y + my[i];
        if (x2 >= 1 && x2 <= 19 && y2 >= 1 && y2 <= 19 && !visited_map[x2][y2] && map[x][y] == map[x2][y2]) {

            if (x == x2) {
                if (dir == 1)
                    bfs(x2, y2, x_start, y_start, n + 1, dir);
                else
                    bfs(x2, y2, x, y, 2, 1);
            }
            else if (y == y2) {
                if (dir == 2)
                    bfs(x2, y2, x_start, y_start, n + 1, dir);
                else
                    bfs(x2, y2, x, y, 2, 2);
            }
            else if (x - x2 == 1 && y2 - y == 1) {
                if (dir == 3)
                    bfs(x2, y2, x_start, y_start, n + 1, dir);
                else
                    bfs(x2, y2, x, y, 2, 3);
            }
            else {
                if (dir == 4)
                    bfs(x2, y2, x_start, y_start, n + 1, dir);
                else
                    bfs(x2, y2, x, y, 2, 4);
            }
        }
    }


    visited_map[x][y] = false;
    if (n == 5) {
        if (dir == 1) {
            if ((y > 5 && map[x][y] == map[x][y - 5]) || (y < 19 && map[x][y] == map[x][y + 1]))
                return;
        }
        else if (dir == 2) {
            if ((x > 5 && map[x][y] == map[x - 5][y]) || (x < 19 && map[x][y] == map[x + 1][y]))
                return;
        }
        else if (dir == 3) {
            if ((x < 15 && y>5 && map[x][y] == map[x + 5][y - 5]) || (x > 1 && y < 19 && map[x][y] == map[x - 1][y + 1]))
                return;
        }
        else if (dir == 4) {
            if ((x > 5 && y > 5 && map[x][y] == map[x - 5][y - 5]) || (x < 19 && y < 19 && map[x][y] == map[x + 1][y + 1]))
                return;
        }

        cout << map[x][y] << "\n" << x_start << " " << y_start;
        exit(0);
    }//¿À¸ñ
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map.assign(MAX, vector<int>(MAX, 0));
    visited_map.assign(MAX, vector<bool>(MAX, false));

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> map[i][j];
        }
    }
    //map

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            if ((map[i][j] == 1 || map[i][j] == 2) && !visited_map[i][j])
                bfs(i, j, i, j, 1, 0);
        }
    }

    cout << 0;

    return 0;
}