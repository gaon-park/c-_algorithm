#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int l, r, c;
char board[30][30][30];
vector<vector<vector<int>>> isused;
int sz, sx, sy; // 시작 지점
int ez, ex, ey; // 도착 지점
int dz[] = { -1, 1 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs() {
	isused.assign(l, vector<vector<int>>(r, vector<int>(c, -1)));
	isused[sz][sx][sy] = 0;
	queue<tuple<int, int, int>> Q;
	Q.push({ sz, sx, sy });

	int z, x, y;
	while (!Q.empty()) {
		tie(z, x, y) = Q.front(); Q.pop();

		if (z == ez && x == ex && y == ey) { // 도착
			return isused[z][x][y];
		}

		for (int i = 0; i < 2; i++) {
			int cz = z + dz[i];
			if (cz < 0 || cz >= l) continue;
			if (board[cz][x][y] == '#' || isused[cz][x][y] >= 0) continue;
			isused[cz][x][y] = isused[z][x][y] + 1;
			Q.push({ cz, x, y });
		}
		
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cy < 0 || cx >= r || cy >= c) continue;
			if (board[z][cx][cy] == '#' || isused[z][cx][cy] >= 0) continue;
			isused[z][cx][cy] = isused[z][x][y] + 1;
			Q.push({ z, cx, cy });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> l >> r >> c;
		if (l == r && r == c && c == 0) break;

		// input
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') { // 시작 위치 저장
						sz = i, sx = j, sy = k;
					}
					else if (board[i][j][k] == 'E') { // 끝나는 위치 저장
						ez = i, ex = j, ey = k;
					}
				}
			}
		}
		int ans = bfs();
		if (ans < 0) { // 탈출 실패
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ans << " minute(s).\n";
		}
	}
}
