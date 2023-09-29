#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int r, c;
vector<vector<char>> board;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> isused;
vector<pair<int, int>> bird;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

pair<int, int> find_parent(pair<int, int> a) {
	pair<int, int> p = parent[a.first][a.second];
	if (a.first == p.first && a.second == p.second) return a;
	return parent[a.first][a.second] = find_parent(p);
}

void union_parent(pair<int, int> a, pair<int, int> b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b.first][b.second] = a;
	}
	else {
		parent[a.first][a.second] = b;
	}
}

// 물을 그룹대로 묶고 물에서 bfs해서 만난 X의 위치를 묶어 반환
queue<pair<int, int>> boiling(queue<pair<int, int>> water) {
	set<pair<int, int>> s;
	while (!water.empty()) { // water 에는 새로 추가되지 않음!
		auto cur = water.front(); water.pop();

		for (int i = 0; i < 4; i++) { // 인접한 곳 체크
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || y < 0 || x >= r || y >= c) continue;

			pair<int, int> key = { x, y };
			if (s.count(key)) continue; // 이미 다음에 녹을 곳임을 확인했음
			if (board[x][y] == 'X') { // 다음에 녹을 곳이면
				s.insert(key); // 반환 리스트에 넣고 
				board[x][y] = '.'; // 녹은 거로 체크
				continue;
			}

			if (find_parent(key) == find_parent(cur)) continue; // 이미 방문했었음
			isused[x][y] = 1; // 방문 체크
			union_parent(key, cur); // 그룹을 합친다
		}
	}
	queue<pair<int, int>> ans;
	for (auto p : s) ans.push(p);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	board.assign(r, vector<char>(c, '.'));
	parent.assign(r, vector<pair<int, int>>());
	queue<pair<int, int>> for_group;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			parent[i].push_back({ i, j }); // 자기 자신을 그룹으로
			if (board[i][j] != 'X') {
				for_group.push({ i, j });
			}
			if (board[i][j] == 'L') {
				bird.push_back({ i, j });
			}
		}
	}

	isused.assign(r, vector<int>(c, 0));
	for_group = boiling(for_group);

	int day = 0;
	while (!for_group.empty() && find_parent(bird[0]) != find_parent(bird[1])) {
		day++;
		for_group = boiling(for_group);
	}
	cout << day;
}
