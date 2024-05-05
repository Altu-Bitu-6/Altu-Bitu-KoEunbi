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
        dfs(cnt + 1); //다음 숫자 선택
        v.pop_back(); //선택한 숫자 제거 
    }
}

int main() {
    cin >> n >> m;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input; //처음 등장하는 숫자만 저장, 방문 기록
        if (visited[input] == 0)
            num.push_back(input);
        visited[input]++;
    }

    sort(num.begin(), num.end());//오름차순 정렬

    for (int i = 0; i < num.size(); i++) {
        v.push_back(num[i]);
        dfs(1);
        v.pop_back();
    }

    return 0;
}
