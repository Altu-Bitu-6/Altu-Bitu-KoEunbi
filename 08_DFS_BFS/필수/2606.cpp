#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> li;
vector <bool> visited_dfs;

void dfs(int idx) {
    visited_dfs[idx] = true;

    for (int i = 1; i <= n; i++) {
        if (li[idx][i] == 1 && !visited_dfs[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, a, b;

    cin >> n;
    li.assign(n, vector<int>(n, 0));
    visited_dfs.assign(n, false);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        li[a - 1][b - 1] = 1;
        li[b - 1][a - 1] = 1;
    }

    vector<int> ans_dfs;
    dfs(0);

    a = 0;
    for (int i = 0; i < n; i++) {
        if (visited_dfs[i]) {
            a++;
        }
    }

    cout << a - 1 << '\n';

    return 0;
}