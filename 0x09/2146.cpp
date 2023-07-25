#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> vect;
vector<vector<int>> visited;
int min_distance = INT_MAX; // 최소 거리
int n;

int rx[] = { -1, 0, 1, 0 };
int ry[] = { 0, 1, 0, -1 };

queue<pair<int, int>> get_ocean(pair<int, int> island) {
	queue<pair<int, int>> ocean = {};
	queue<pair<int, int>> que = {};
	que.push(island);

	while (!que.empty()) {
		auto p = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = p.first + rx[i];
			int y = p.second + ry[i];
			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			// 땅, 이어서 탐색
			if (vect[x][y] == 1 && visited[x][y] != INT_MAX) {
				que.push({ x, y });
				// 방문한 땅은 INT_MAX
				visited[x][y] = INT_MAX;
			}
			// 바다, ocean.push()
			else if (vect[x][y] == 0 && visited[x][y] == 0) {
				ocean.push({ x, y });
				visited[x][y] = 1;
			}
		}
	}

	return ocean;
}

// 탐색
void bfs(queue<pair<int, int>> que) {
	while (!que.empty()) {
		pair<int, int> p = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = p.first + rx[i];
			int y = p.second + ry[i];
			if (x < 0 || y < 0 || x >= n || y >= n) continue;

			// 새로 만나는 땅. 현재 검색중인 다리의 시작땅은 INT_MAX로 설정하고 있음
			// 이전에 탐색했던 땅은 0보다 작도록 세팅
			if (vect[x][y] == 1 && visited[x][y] != INT_MAX) {
				// 최소 거리 비교
				min_distance = min(min_distance, visited[p.first][p.second]);
			}
			// 바다, 계속 탐색
			else if (vect[x][y] == 0 && visited[x][y] == 0) {
				que.push({ x, y });
				visited[x][y] = visited[p.first][p.second] + 1;
			}
		}
	}
}

// used < 0
void init_visited(int used) {
	// visited 바다 구역(테두리 제외) 방문 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == INT_MAX) visited[i][j] = used;
			else if (visited[i][j] > 0) visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> v = {};
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		vect.push_back(v);
	}
	visited.assign(n, vector<int>(n, 0));

	int used = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 새로운 땅 발견
			if (vect[i][j] == 1 && visited[i][j] != INT_MAX && visited[i][j] >= 0) {
				// 방문한 땅은 INT_MAX
				visited[i][j] = INT_MAX;
				bfs(get_ocean({ i, j }));
				init_visited(used--);
			}
		}
	}

	cout << min_distance;

	return 0;
}