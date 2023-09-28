#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
vector<vector<int>> board;
int isused[1005][1005][15];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	board.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}

	isused[0][0][0] = 1;
	queue<tuple<int, int, int>> Q;
	Q.push({ 0, 0, 0 });
	while (!Q.empty()) {
		auto [cx, cy, cw] = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cx + dx[i];
			int y = cy + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			
			int w = cw + board[x][y];
			int plus = 1;
			if (board[x][y] && isused[cx][cy][cw] % 2 == 0) plus++; // 만약 밤에 만난 벽이라면
			if (k < w) continue; // 벽을 뚫을 수 있는 횟수를 넘음
			if (isused[x][y][w] > 0 && isused[x][y][w] <= isused[cx][cy][cw] + plus) continue;
			isused[x][y][w] = isused[cx][cy][cw] + plus;
			Q.push({ x, y, w });
		}
	}

	int ans = 0x7fffffff;
	for (int i = 0; i <= k; i++) {
		if (isused[n - 1][m - 1][i] == 0) continue;
		ans = min(ans, isused[n - 1][m - 1][i]);
	}

	if (ans == 0 || ans == 0x7fffffff) cout << -1;
	else cout << ans;
}
