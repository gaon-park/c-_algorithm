#include <bits/stdc++.h>

using namespace std;

int n, k;
int cost[15][15];
int all_used, is_used;
int ans = 0x7fffffff;

// 현재 행성 위치, 현재까지의 비용
void backtracking(int cur, int cur_cost) {
	if ((is_used | (1 << cur)) == all_used) { // 모든 정점을 방문했음
		ans = min(ans, cur_cost);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used & (1 << i)) continue;
		is_used |= (1 << i);
		backtracking(i, cur_cost + cost[cur][i]);
		is_used &= ~(1 << i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	all_used = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	is_used |= (1 << k);
	backtracking(k, 0);
	cout << ans;
}