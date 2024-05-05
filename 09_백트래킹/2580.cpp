#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
vector<pair<int, int>> zeroPoint;
int zeroCnt;
bool flag = false;

void dfs(int x, int y, int cnt) {
    if (flag) //완성시 정지
        return;

    bool possible[10];
    for (int i=1; i<=9; i++)
        possible[i] = true;

    for (int i = 1; i <= 9; i++) { //가로방향 검사
        if (y== i) continue;
        possible[map[x][i]] = false;
    }
    for (int i = 1; i <= 9; i++) { // 세로 방향 검사
        if (x== i) continue;
        possible[map[i][y]] = false;
    }

    int xx = 0; //칸안에서 검사사
    if (x%3==0)
        xx= x-3;
    else
        xx= x-(x%3);

    int yy = 0;
    if (y%3==0)
        yy = y-3;
    else 
        yy = y-(y%3);


    for (int i=xx+1; i<=xx+3; i++) {
        for (int j=yy+1; j<= yy+3; j++) {
            if (x== i && y== j)
                continue;

            possible[map[i][j]] = false;
        }
    }

    for (int i=1; i <= 9; i++) {
        if (possible[i]) {
            if (cnt == zeroCnt) { //마지막 빈칸 채웠을 시 완성
                map[x][y] = i;
                for (int i=1; i<=9; i++) {
                    for (int j=1; j<=9; j++) {
                        cout << map[i][j] << ' ';
                    }
                    cout << '\n';
                }
                flag = true;
                return;
            } //다음 빈칸으로 진행
            else {
                map[x][y]=i;
                dfs(zeroPoint[cnt].first, zeroPoint[cnt].second, cnt+1);
                map[x][y]=0;
            }
        }
    }
}

int main(void) {
    for (int i=1; i<=9; i++) { //입력받기
        for (int j=1; j<=9; j++) {
            cin >> map[i][j];
            if (map[i][j]==0) {
                zeroPoint.push_back({i, j});
                zeroCnt++;
            }
        }
    }
    dfs(zeroPoint[0].first, zeroPoint[0].second, 1);
    return 0;
}
