#include <bits/stdc++.h>

using namespace std;

int v, e;
int st;
vector<pair<int, int>> dist[20005]; // {idx, cost}
int ans[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {cost, idx}

void dijkstra() {
	for (int i = 1; i <= v; i++) {
		ans[i] = 1e9;
	}
	ans[st] = 0;
	q.push({ 0, st });
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		if (ans[p.second] < p.first) continue;

		for (auto a : dist[p.second]) {
			if (ans[a.first] <= ans[p.second] + a.second) continue;
			ans[a.first] = ans[p.second] + a.second;
			q.push({ ans[p.second], a.first });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	cin >> st;
	while (e--) {
		int a, b, d;
		cin >> a >> b >> d;
		dist[a].push_back({ b, d });
	}

	dijkstra();
	for (int i = 1; i <= v; i++) {
		if (i == st) cout << "0\n";
		else if (ans[i] == 1e9) cout << "INF\n";
		else cout << ans[i] << "\n";
	}
}