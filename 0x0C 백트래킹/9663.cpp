#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int col[15], LURD[15 * 2], RULD[15 * 2];

void func(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (col[i] || LURD[row - i + n] || RULD[row + i]) continue;
		col[i] = 1;
		LURD[row - i + n] = 1;
		RULD[row + i] = 1;
		func(row + 1);
		col[i] = 0;
		LURD[row - i + n] = 0;
		RULD[row + i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}