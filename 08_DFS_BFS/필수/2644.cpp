#include <iostream>
#include <vector>

using namespace std;

int n, a, b, flag;
vector<vector<int>> li;
vector <bool> visited_dfs;
vector <int> ans;

void dfs(int idx) {
    visited_dfs[idx] = true;
    if (idx == b) {
        flag = 1;
    } //b�� ������ Ž�� ����
    ans[idx]++;

    for (int i = 1; i <= n; i++) {
        if (flag != 1 && li[idx][i] == 1 && !visited_dfs[i]) {
            ans[i] = ans[idx]; //�ش� ��� ans�� ����
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    int x, y;
    flag = 0;

    cin >> n;
    li.assign(n + 1, vector<int>(n + 1, 0));
    visited_dfs.assign(n + 1, false);
    ans.assign(n + 1, 0);

    cin >> a >> b;
    if (a > b) {
        m = a;
        a = b;
        b = m;
    } //a���� �����ϵ���

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        li[x][y] = 1;
        li[y][x] = 1;
    }//��� �Է¹ޱ�

    dfs(a); //Ž��

    cout << ans[b] - 1 << '\n';

    return 0;
}