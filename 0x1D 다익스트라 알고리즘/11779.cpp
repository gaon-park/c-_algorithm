#include <bits/stdc++.h>

using namespace std;

int n, m;
int st, en;
int cost[1005];
int pre[1005]; // 시작점에서 나에게로 올 때 경유하는 정점
vector<pair<int, int>> adj[1005]; // {cost, idx}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {cost, idx}

void dijkstra() {
	for (int i = 0; i <= n; i++) cost[i] = 1e9 + 10;
	cost[st] = 0;
	q.push({0, st});

	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		if (cost[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (cost[nxt.second] <= nxt.first + cost[cur.second]) continue;
			cost[nxt.second] = nxt.first + cost[cur.second];
			pre[nxt.second] = cur.second;
			q.push({cost[nxt.second], nxt.second});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	cin >> st >> en;
	dijkstra();

	cout << cost[en] << "\n"; // 최소 비용
	stack<int> path;
	while (en != st) {
		path.push(en);
		en = pre[en];
	}
	path.push(st);
	cout << path.size() << "\n";
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
}