#include <iostream>
#include <vector>

using namespace std;

vector <int> v[1000000];
bool visited[1000000] = { false, };
int num[1000000];


int dfs(int n) {
    if (num[n] != 0)
        return num[n];

    visited[n] = true;

    int ans = 1;
    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if (visited[next])
            continue;

        ans += dfs(next);
    }
    num[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int root;
    int n, q, s, e;

    cin >> n >> root >> q;

    for (int i = 0; i < n - 1; i++) {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    num[root] = dfs(root);

    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << num[s] << '\n';
    }

    return 0;
}