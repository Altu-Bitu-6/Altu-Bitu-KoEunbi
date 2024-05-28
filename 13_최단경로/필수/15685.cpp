#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };

void curve(int x, int y, int d, int g) { 
    vector <int> v; //방향 저장 벡터
    int c = 0, size;

    v.push_back(d); //초기방향
    while (c++ < g) { //g세대까지 커브 생성
        if (c == 1) //1세대인 경우
            v.push_back((d + 1) % 4);
        else { // 그 이후 세대
            size = v.size();
            for (int i = 0; i < size; i++) {
                if (i < size / 2)
                    v.push_back((v[i] + 2) % 4); //180도 회전
                else
                    v.push_back(v[i]); //그대로
            }
        }
    }

    map[y][x] = 1; //시작점
    size = v.size();
    for (int i = 0; i < size; i++) {
        y += dy[v[i]]; 
        x += dx[v[i]]; //좌표 갱신
        map[y][x] = 1; 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans = 0;
    int x, y, d, g;

    cin >> n;

    while (n--) {
        cin >> x >> y >> d >> g;
        curve(x, y, d, g); //커브 생성
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1) //정사각형이 존재하는 경우 (네 꼭짓점이 1)
                ans++; //갯수 증가
        }
    }

    cout << ans;

    return 0;
}