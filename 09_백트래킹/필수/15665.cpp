#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10001] = { 0, };

int n, m;
vector<int> num;
vector<int> v;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < num.size(); i++) {
        v.push_back(num[i]);
        dfs(cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (visited[input] == 0)
            num.push_back(input);
        visited[input]++;
    }

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        v.push_back(num[i]);
        dfs(1);
        v.pop_back();
    }

    return 0;
}