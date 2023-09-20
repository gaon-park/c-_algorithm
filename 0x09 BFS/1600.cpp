#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Move {
	int horseCnt; // 말의 이동이 얼마나 더 가능한가?
	int x, y;
};

const int INF = 0x7f7f7f7f;
int k;
int w, h;
int board[205][205];
int isused[35][205][205]; // K 번 말이 되어 이동했다

// 인접한 곳으로 이동할 경우
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 말의 이동을 사용할 경우
int dx_h[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy_h[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

bool range(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w) return false;
	if (board[x][y] == 1) return false; // 장애물
	return true;
}

void bfs() {
	queue<Move> q;
	q.push({ 0, 0, 0 });
	isused[0][0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.horseCnt < k) {
			for (int i = 0; i < 8; i++) {
				int x = cur.x + dx_h[i];
				int y = cur.y + dy_h[i];
				if (!range(x, y)) continue;
				if (isused[cur.horseCnt + 1][x][y]) continue; // 말을 cur.horstCnt + 1번 써서 x, y로 온 적이 있음
				isused[cur.horseCnt + 1][x][y] = isused[cur.horseCnt][cur.x][cur.y] + 1;
				q.push({ cur.horseCnt + 1, x, y });
			}
		}

		for (int i = 0; i < 4; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			if (!range(x, y)) continue;
			if (isused[cur.horseCnt][x][y]) continue;
			isused[cur.horseCnt][x][y] = isused[cur.horseCnt][cur.x][cur.y] + 1;
			q.push({ cur.horseCnt, x, y });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	bfs();
	int ans = INF;
	for (int i = 0; i < k + 1; i++) {
		if (isused[i][h - 1][w - 1])
			ans = min(ans, isused[i][h - 1][w - 1]);
	}
	if (ans == INF) cout << -1;
	else cout << ans - 1;
}
