#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans[2];
int board[10][10];
int lurd[20]; // c - r + n
int ldru[20]; // c + r

/*
체스판을 생각할 때 검정칸과 흰칸은 비숍의 움직임에 있어 서로 영향을 주지 않음
	ans = 검정칸에 놓는 경우 + 흰칸에 놓는 경우
*/
void solve(int idx, int cnt, int color) {
	if (idx >= n * n) return;

	for (int i = idx; i < n * n; i++) {
		int x = i / n;
		int y = i % n;
		if (color && (x + y) % 2 != 0) {
			continue;
		}
		if (!color && (x + y) % 2 == 0) {
			continue;
		}
		if (!board[x][y]) continue;
		if (lurd[y - x + n] || ldru[x + y]) continue;
		lurd[y - x + n] = 1;
		ldru[x + y] = 1;
		ans[color] = max(ans[color], cnt + 1);
		solve(i + 1, cnt + 1, color);
		lurd[y - x + n] = 0;
		ldru[x + y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];
	
	solve(0, 0, 0);
	solve(0, 0, 1);
	cout << ans[0] + ans[1];
}
