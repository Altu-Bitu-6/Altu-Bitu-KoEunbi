#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 19;
int flag = 0;
vector<vector<int>> map;
vector<vector<int>> li_b;
vector<vector<int>> li_w;
vector <bool> visited_dfs;

void dfs(int idx) {
    visited_dfs[idx] = true;

    for (int i = 1; i <= N; i++) {
        if (li[idx][i] == 1 && !visited_dfs[i]) {
            dfs(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i, j, idx_b = 0, idx_w = 0;

    map.assign(N, vector<int>(N, 0));
    li_b.assign(N * N, vector<int>(N, vector<int>(N, 0)));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> m;
            map[i][j] = m;

            if (m == 1)
                li_b[idx_b][i][j] = li_b[idx_b++][j][i] = 1;
            else if (m == 2)
                li_w[idx_w][i][j] = li_w[idx_w++][j][i] = 1;
        }
    } //바둑판 입력 받기


    li_w.assign(white, vector<int>(white, 0));




    return 0;
}