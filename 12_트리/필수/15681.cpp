#include <iostream>
#include <vector>

using namespace std;

vector <int> v[1000000];
bool visited[1000000] = { false, };
int num[1000000];


int dfs(int n) { //깊이 우선 탐색
    if (num[n] != 0) //이미 계산되었다면 반환
        return num[n];

    visited[n] = true; //방문 표시

    int ans = 1; //초기값 초기화
    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if (visited[next]) //방문 되었다면 패스
            continue;

        ans += dfs(next); //인접토드 크기 더하기
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
    //루트노드부터 서브트리 크기 계산
    
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << num[s] << '\n';
    }

    return 0;
}
