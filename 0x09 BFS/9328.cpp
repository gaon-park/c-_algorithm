#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int h, w;
vector<vector<char>> board;
vector<vector<int>> isused;
unordered_map<char, vector<pair<int, int>>> door;
queue<pair<int, int>> Q;
int ans = 0; // 훔친 문서 수
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 열 수 있는 문을 다 열고, 열린 문으로 지나갈 수 있는 루트를 큐에 추가한다
void open_door(char key) {
	for (auto p : door[key]) {
		board[p.first][p.second] = '.';
		bool can_visit = false;
		for (int i = 0; i < 4; i++) {
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			if ((x < 0 || y < 0 || x >= h || y >= w) || isused[x][y]) { // 가장자리이거나 방문 가능
				can_visit = true;
				break;
			}
		}
		if (can_visit) {
			Q.push(p);
			isused[p.first][p.second] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		// init
		cin >> h >> w;
		board.assign(h, vector<char>(w, '.'));
		isused.assign(h, vector<int>(w, 0));
		door.clear();
		ans = 0;

		// input
		unordered_set<char> first_key; // 가장자리에 키가 있는 경우
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if ('A' <= board[i][j] && board[i][j] <= 'Z') {
					door[board[i][j]].push_back({ i, j });
				}

				if ((i == 0 || i == h - 1) || (j == 0 || j == w - 1)) { // 가장자리
					if (board[i][j] == '*' || isupper(board[i][j])) continue; // 벽이면 스킵
					Q.push({ i, j });
					isused[i][j] = 1;
					if (board[i][j] == '$') {
						board[i][j] = '.';
						ans++;
					}
					else if (islower(board[i][j]) && !first_key.count(board[i][j])) {
						first_key.insert(board[i][j]);
						board[i][j] = '.';
					}
				}
			}
		}
		string have_key;
		cin >> have_key;
		for (char c : have_key) {
			if (c == '0') break;
			open_door(toupper(c));
			first_key.erase(c);
		}
		for (char c : first_key) open_door(toupper(c));


		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++) {
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (x < 0 || y < 0 || x >= h || y >= w) continue;
				if (isupper(board[x][y]) || board[x][y] == '*') continue; // 막혀있음
				if (isused[x][y]) continue; // 방문한 적 있음
				isused[x][y] = 1;
				Q.push({ x, y });

				if (board[x][y] == '$') ans++;
				else if (islower(board[x][y])) { // found key
					open_door(towupper(board[x][y]));
				}
			}
		}

		cout << ans << "\n";
	}
}
