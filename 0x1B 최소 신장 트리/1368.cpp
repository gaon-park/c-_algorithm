#include <bits/stdc++.h>

using namespace std;

int n;
int cost[310];
int adj[310][310];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> cost[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	// 우물을 만드는데 필요한 비용을 가상의 점과 연결하는 비용으로 생각한다
	for (int i = 0; i < n; i++) {
		adj[i][n] = cost[i];
		adj[n][i] = cost[i];
	}

	int isused[310] = {};
	isused[n] = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // link cost, idx
	for (int i = 0; i < n; i++) {
		pq.push({ adj[i][n], i });
	}
	
	int sum = 0;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (isused[cur.second]) continue;
		sum += cur.first;
		isused[cur.second] = 1;

		for (int i = 0; i <= n; i++) {
			if (isused[i] || i == cur.second) continue;
			pq.push({ adj[cur.second][i], i });
		}
	}

	cout << sum;
}