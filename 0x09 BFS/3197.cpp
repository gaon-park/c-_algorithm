#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int r, c;
vector<vector<char>> board;
vector<vector<int>> parent;
vector<vector<int>> isused;
vector<int> bird;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int find_parent(int a) {
	int i = a / c, j = a % c;
	if (a == parent[i][j]) return a;
	return parent[i][j] = find_parent(parent[i][j]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b / c][b % c] = a;
	}
	else {
		parent[a / c][a % c] = b;
	}
}

// 물을 그룹대로 묶고 물에서 bfs해서 만난 X의 위치를 묶어 반환
queue<int> boiling(queue<int> water) {
	unordered_set<int> s;
	while (!water.empty()) {
		int cx = water.front() / c;
		int cy = water.front() % c;
		int c_key = water.front();
		water.pop();

		for (int i = 0; i < 4; i++) {
			int x = cx + dx[i];
			int y = cy + dy[i];
			if (x < 0 || y < 0 || x >= r || y >= c) continue;

			int key = x * c + y;
			if (s.count(key)) continue;
			if (board[x][y] == 'X') {
				s.insert(x * c + y);
				board[x][y] = '.';
				continue;
			}

			if (find_parent(key) == find_parent(c_key)) continue;
			isused[x][y] = 1;
			union_parent(cx * c + cy, x * c + y);
		}
	}
	queue<int> ans;
	for (int idx : s) {
		ans.push(idx);
	}
	return ans;
}

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%3d ", find_parent(i * c + j));
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	board.assign(r, vector<char>(c, '.'));
	parent.assign(r, vector<int>(c, 0));
	queue<int> for_group;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			parent[i][j] = i * c + j; // 자기 자신을 그룹으로
			if (board[i][j] != 'X') {
				for_group.push(i * c + j);
			}
			if (board[i][j] == 'L') {
				bird.push_back(i * c + j);
			}
		}
	}

	isused.assign(r, vector<int>(c, 0));
	for_group = boiling(for_group);

	int day = 0;
	while (!for_group.empty() && find_parent(bird[0]) != find_parent(bird[1])) {
		day++;
		for_group = boiling(for_group);
		//cout << "day " << day << "\n";
		//print();
	}
	cout << day;
}
