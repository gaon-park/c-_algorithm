#include <bits/stdc++.h>
using namespace std;

int n, max_num;
int board[21][21], board2[21][21];

// 게임판 90도씩 기울이기
void rotate() {
	int tmp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}
}

// 왼쪽으로 슬라이드
void slide_left() {
	for (int i = 0; i < n; i++) {
		queue<int> Q;
		for (int j = 0; j < n; j++) {
			if (board2[i][j] > 0) Q.push(board2[i][j]);
		}
		int idx = 0;
		while (!Q.empty()) {
			int num = Q.front();
			Q.pop();
			if (!Q.empty() && Q.front() == num) {
				num += Q.front();
				Q.pop();
			}
			board2[i][idx++] = num;
		}
		while (idx < n) board2[i][idx++] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	// 최대 5번 이동 + 회전 방향 4개 => 4진법 5자리
	for (int tmp = 0; tmp < (1 << (2 * 5)); tmp++) {
		// deep copy
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board2[i][j] = board[i][j];
			}
		}
		// 4진법
		int brute = tmp;
		// 5개의 3이하 숫자 뽑기
		for (int j = 0; j < 5; j++) {
			int dir = brute % 4;
			brute /= 4;

			// 돌리고
			// 결론적으로 돌린 결과를 다시 반대로 돌려놓지 않더라도, 모든 경우의 수를 따져보기 때문에 원복할 필요가 없다
			while (dir--) rotate();
			slide_left();

			// cout << dir << " ";
		}

		// find_max
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				max_num = max(max_num, board2[i][j]);
			}
		}
		// cout << "\n";
	}

	cout << max_num;
}