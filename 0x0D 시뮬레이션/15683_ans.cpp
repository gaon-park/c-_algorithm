#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<vector<int>> ground, ground2;
vector<pair<int, int>> cctv;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void view(int x, int y, int d) {
	d %= 4;
	while (true) {
		x += dx[d];
		y += dy[d];
		if (x < 0 || y < 0 || x >= n || y >= m || ground2[x][y] == 6) return;
		if (ground2[x][y] != 0) continue;
		ground2[x][y] = 7;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			if (tmp != 0 && tmp != 6) cctv.push_back({ i, j });
			if (tmp == 0) ans++;
		}
		ground.push_back(v);
	}
	ground2.assign(n, vector<int>(m, 0));

	// 4진법 사용. (1 << (2 * cctv.size())) 4의 cctv.size()제곱
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		// deep copy
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ground2[i][j] = ground[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (ground[x][y] == 1) {
				view(x, y, dir);
			}
			else if (ground[x][y] == 2) {
				view(x, y, dir);
				view(x, y, dir + 2);
			}
			else if (ground[x][y] == 3) {
				view(x, y, dir);
				view(x, y, dir + 1);
			}
			else if (ground[x][y] == 4) {
				view(x, y, dir);
				view(x, y, dir + 1);
				view(x, y, dir + 2);
			}
			else if (ground[x][y] == 5) {
				view(x, y, dir);
				view(x, y, dir + 1);
				view(x, y, dir + 2);
				view(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				val += ground2[i][j] == 0;
			}
		}
		ans = min(ans, val);
	}

	cout << ans;
}