#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char board[5][5];
int ans;
vector<int> brute(25, 1);

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solve() {
	pair<int, int> st = { -1, -1 };
	int cnt = 0;
	int isused = 0;
	for (int i = 0; i < 25; i++) {
		if (brute[i] == 0) {
			isused |= (1 << (i + 1)); // 방문해야 할 곳
			int x = i / 5;
			int y = i % 5;
			cnt += (board[x][y] == 'S');
			if (st.first == -1) {
				st = { x, y };
			}
		}
	}

	if (cnt < 4) return; // 4번 규칙에 어긋남

	int ch = 1 << ((st.first * 5 + st.second) + 1); // 방문으로 체크할 값
	queue<pair<int, int>> Q;
	Q.push(st);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || y < 0 || x >= 5 || y >= 5) continue; // 범위 밖
			
			int key = 1 << ((x * 5 + y) + 1); 
			if (!(isused & key)) continue; // 방문해야 할 곳이 아니라면
			if (ch & key) continue; // 이미 방문한 곳이라면
			ch |= key; // 방문 처리
			Q.push({ x, y });
		}
	}
	ans += (isused == ch); // 방문해야 할 곳을 모두 들렀으면 + 1
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	fill(brute.begin(), brute.begin() + 7, 0);

	do {
		solve();
	} while (next_permutation(brute.begin(), brute.end()));
	
	cout << ans;
}
