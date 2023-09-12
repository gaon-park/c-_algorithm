#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 0x3f3f3f3f;
using namespace std;

int n, m;
int board[105][105];
int nxt[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 105; i++) {
		fill(board[i], board[i] + 105, INF);
		board[i][i] = 0;
	}

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < board[a][b]) { // 갱신이 일어난다면
			board[a][b] = c;
			nxt[a][b] = b;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 거쳐가는 경로가 더 최소 비용이라면
				if (board[i][k] + board[k][j] < board[i][j]) {
					board[i][j] = board[i][k] + board[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	// 최소 비용 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == INF) cout << "0 ";
			else cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 0 || board[i][j] == INF) {
				cout << "0\n";
				continue;
			}

			vector<int> path;
			int st = i;
			while (st != j) {
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << " ";
			for (auto x : path) cout << x << " ";
			cout << "\n";
		}
	}
}
