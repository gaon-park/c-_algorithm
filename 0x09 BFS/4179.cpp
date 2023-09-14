#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int r, c;
char board[1005][1005];
int fire_used[1005][1005];
int jihun_used[1005][1005];
queue<pair<int, int>> jihun;
queue<pair<int, int>> fire;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				jihun.push({ i, j });
				jihun_used[i][j] = 1;
			}
			else if (board[i][j] == 'F') {
				fire.push({ i, j });
				fire_used[i][j] = 1;
			}
		}
	}

	int cur = 0;
	while (!jihun.empty()) {
		cur++;
		int fireSize = fire.size();
		for (int i = 0; i < fireSize; i++) {
			// cur 시간대 불의 사이즈만큼만 확장
			auto f = fire.front(); fire.pop();
			for (int j = 0; j < 4; j++) {
				int x = f.first + dx[j];
				int y = f.second + dy[j];
				if (x < 0 || y < 0 || x >= r || y >= c) continue;
				if (board[x][y] == '#' || fire_used[x][y]) continue;
				fire.push({ x, y });
				fire_used[x][y] = 1;
			}
		}

		int jihunSize = jihun.size();
		for (int i = 0; i < jihunSize; i++) {
			auto ji = jihun.front(); jihun.pop();
			for (int j = 0; j < 4; j++) {
				int x = ji.first + dx[j];
				int y = ji.second + dy[j];
				if (x < 0 || y < 0 || x >= r || y >= c) {
					// 탈출 성공
					cout << cur;
					return 0;
				}
				if (board[x][y] == '#' || jihun_used[x][y] || fire_used[x][y]) continue;
				jihun.push({ x, y });
				jihun_used[x][y] = 1;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
