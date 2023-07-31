#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, ans = INT_MAX;
vector<vector<int>> ground;
vector<vector<int>> cctv;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void view(pair<int, int> cur, int d) {
	queue<pair<int, int>> Q;
	Q.push(cur);

	while (!Q.empty()) {
		auto p = Q.front();
		Q.pop();

		int nx = p.first + dx[d];
		int ny = p.second + dy[d];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (ground[nx][ny] == 6) continue;
		Q.push({ nx, ny });
		ground[nx][ny] = 1;
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

vector<vector<int>> deep_copy(vector<vector<int>> origin) {
	vector<vector<int>> res(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[i][j] = origin[i][j];
		}
	}
	return res;
}

void dfs(int cur) {
	if (cur >= cctv.size()) {
		// 방문하지 못한 곳 세기
		ans = min(ans, count());
		return;
	}

	auto arr = cctv[cur];
	pair<int, int> p = { arr[0], arr[1] };
	vector<vector<int>> origin = deep_copy(ground);
	int end = (arr[2] == 2 ? 2 : (arr[2] == 5 ? 1 : 4));
	for (int i = 0; i < 4; i++) {
		switch (arr[2])
		{
		case 1:
			view(p, i);
			break;
		case 2: // 양옆으로 뻗어나가는 모양
			view(p, i);
			view(p, (i + 2) % 4);
			break;
		case 3: // 90도 
			view(p, i);
			view(p, (i + 1) % 4);
			break;
		case 4: // 왼, 위, 오 3방향
			view(p, i);
			view(p, (i + 1) % 4);
			view(p, (i + 2) % 4);
			break;
		case 5: // 4방향
			view(p, i);
			view(p, (i + 1) % 4);
			view(p, (i + 2) % 4);
			view(p, (i + 3) % 4);
			break;
		}

		dfs(cur + 1);
		// 원상복구
		ground = deep_copy(origin);
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
			if (tmp != 0 && tmp != 6) cctv.push_back({ i, j, tmp });
		}
		ground.push_back(v);
	}

	dfs(0);
	cout << ans;
}