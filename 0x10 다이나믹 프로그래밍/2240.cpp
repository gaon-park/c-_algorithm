#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int a[1005]; // i번째 자두가 떨어지는 위치
int d[1005][35][3]; // i번째 자두가 떨어질 때 j번 이동해서 k위치로 이동 = 먹은 자두의 수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T >> W;
	for (int i = 1; i <= T; i++) cin >> a[i];

	for (int i = 1; i <= T; i++) {
		// i번째 자두가 1번 나무에 떨어지는 경우
		d[i][0][1] = d[i - 1][0][1] + (a[i] == 1 ? 1 : 0);
		for (int j = 1; j <= W; j++) { // j번 이동
			if (i < j) break; // 현재 시간보다 많이 이동할 수 없음
			if (a[i] == 1) { // 1번 나무인 경우
				// 이번 자두를 먹는 동시에
				// 2번 나무에서 이동해 왔을 경우와 그대로 있을 경우 중 최대 선택
				d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
				// 이번 자두를 먹지 않는 경우
				d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
			}
			else { // 2번 나무
				// 이번 자두를 먹지 않는 경우
				d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
				// 이번 자두를 먹기 위해 움직이는 경우
				d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= W; j++) {
		ans = max({ ans, d[T][j][1], d[T][j][2] });
	}
	cout << ans;
}
