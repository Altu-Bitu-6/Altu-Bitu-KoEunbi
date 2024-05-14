#include <iostream>

using namespace std;

int n, m, ans;
int xx[] = { -1, 0, 1, 0 };
int yy[] = { 0,1,0,-1 };
int map[51][51];

void dfs(int x, int y, int d) {
	int nd, nx, ny;

	if (map[x][y] == 0) {
		map[x][y] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		nd = (d + 3 - i) % 4;
		nx = x + xx[nd];
		ny = y + yy[nd];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (map[nx][ny] == 0)
			dfs(nx, ny, nd);
	}

	nd = (d + 2) % 4;
	nx = x + xx[nd];
	ny = y + yy[nd];

	if (map[nx][ny] == 1) {
		cout << ans;
		exit(0);
	}

	dfs(nx, ny, d);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r, c, d;

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(r, c, d);

	return 0;
}