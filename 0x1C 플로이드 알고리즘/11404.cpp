#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 105; i++) {
		fill(board[i], board[i] + 105, 100'000'000); // init 최대 비용
	}

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a][b] = min(board[a][b], c);
	}

	for (int i = 1; i <= n; i++) board[i][i] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 100'000'000) cout << "0 ";
			else cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
