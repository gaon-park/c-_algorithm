#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<char>> MAP;
vector<vector<int>> visited;
int n;
int rx[] = { -1, 0, 1, 0 };
int ry[] = { 0, 1, 0, -1 };

void bfs(char c1, char c2, queue<pair<int, int>> q) {
	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = p.first + rx[i];
			int y = p.second + ry[i];
			if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] != 0) continue;
			if (MAP[x][y] == c1 || MAP[x][y] == c2) {
				visited[x][y] = 1;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<char> v = {};
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			v.push_back(s[j]);
		}
		MAP.push_back(v);
	}

	visited.assign(n, vector<int>(n, 0));
	// r, g, b
	int rgb_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push({ i, j });
				bfs(MAP[i][j], MAP[i][j], q);
				rgb_cnt++;
			}
		}
	}

	visited.assign(n, vector<int>(n, 0));
	// r+g, b
	int rb_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push({ i, j });
				if (MAP[i][j] == 'R' || MAP[i][j] == 'G') {
					bfs('R', 'G', q);
				}
				else bfs('B', 'B', q);
				rb_cnt++;
			}
		}
	}

	cout << rgb_cnt << " " << rb_cnt;

	return 0;
}