#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int board[1000][1000];
int dist[1000][1000][2]; // [0][0][0] : 벽 안 부수고 가는 경로, [0][0][1]: 벽 부수고 온 경로

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int func() {
	queue<tuple<int, int, bool>> Q;
	dist[0][0][0] = dist[0][0][1] = 1;
	Q.push({ 0, 0, false });
	while (!Q.empty()) {
		int cx, cy;
		bool wall;
		tie(cx, cy, wall) = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cx + dx[i];
			int y = cy + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (board[x][y] && dist[x][y][1] == 0) {
				if (wall) continue; // 벽을 만났는데 이미 벽을 깨고 왔던 경우
				// 깰 수 있다!
				dist[x][y][1] = dist[cx][cy][0] + 1;
				Q.push({ x, y, true });
			}
			else if (board[x][y] == 0) { // 그냥 지나갈 수 있음
				if (wall && dist[x][y][1] == 0) { // 벽을 깨고 왔으니 1로 진행
					dist[x][y][1] = dist[cx][cy][1] + 1;
					Q.push({ x, y, wall });
				}
				else if (!wall && dist[x][y][0] == 0) { // 벽을 안 깨고 왔으니 0으로 진행
					dist[x][y][0] = dist[cx][cy][0] + 1;
					Q.push({ x, y, wall });
				}
				
			}
		}
	}

	if (dist[n - 1][m - 1][0] == 0) dist[n - 1][m - 1][0] = 0x7fffffff;
	if (dist[n - 1][m - 1][1] == 0) dist[n - 1][m - 1][1] = 0x7fffffff;

	if (dist[n - 1][m - 1][0] == dist[n - 1][m - 1][1] && dist[n - 1][m - 1][0] == 0x7fffffff) return -1;
	return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	cout << func();
}
