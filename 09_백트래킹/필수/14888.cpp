#include <iostream>

using namespace std;

int op[4]; //연산자
int num[11]; //숫자
int maxi = -1000000000, mini = 1000000000; //최대 최소 설정 위해
int n;

void dfs(int sum, int sub, int mul, int div, int a, int ans) {
    if (a == n - 1) {
        if (ans < mini)
            mini = ans;
        if (ans > maxi)
            maxi = ans;
    } //최대최소 정답 조정

    if (sum > 0) dfs(sum - 1, sub, mul, div, a + 1, ans + num[a + 1]); //덧셈 인자로 계산해서 탐색
    if (sub > 0) dfs(sum, sub - 1, mul, div, a + 1, ans - num[a + 1]); //뺄셈
    if (mul > 0) dfs(sum, sub, mul - 1, div, a + 1, ans * num[a + 1]); //곱하기
    if (div > 0) dfs(sum, sub, mul, div - 1, a + 1, ans / num[a + 1]); //나누기
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(op[0], op[1], op[2], op[3], 0, num[0]);

    cout << maxi << "\n" << mini;

    return 0;
}
