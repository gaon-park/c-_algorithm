#include <bits/stdc++.h>

using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1005]; // {cost, idx}

int dijkstra(int st, int en) {
	// init
	int cost[1005] = {};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {cost, idx}
	for (int i = 0; i <= n; i++) {
		cost[i] = 1e9;
	}
	cost[st] = 0;
	q.push({0, st});

	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		if (cost[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (cost[nxt.second] <= nxt.first + cost[cur.second]) continue;
			cost[nxt.second] = nxt.first + cost[cur.second];
			q.push({cost[nxt.second], nxt.second});
		}
	}
	return cost[en];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dijkstra(i, x) + dijkstra(x, i));
	}

	cout << ans;
}