#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int const INF = 1e9;
int n, e;
int v1, v2;
vector<pair<int, int>> adj[805]; // {dist, idx}
int fromSt[805], fromV1[805], fromV2[805];

void dijkstra(int st, int d[805]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i <= n; i++) d[i] = INF;
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] < cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	cin >> v1 >> v2;
	dijkstra(1, fromSt);
	dijkstra(v1, fromV1);
	dijkstra(v2, fromV2);
	// st -> v1 -> v2 -> en
	int first = (fromSt[v1] == INF || fromV1[v2] == INF || fromV2[n] == INF) ? INF : fromSt[v1] + fromV1[v2] + fromV2[n];
	// st -> v2 -> v1 -> en
	int second = (fromSt[v2] == INF || fromV2[v1] == INF || fromV1[n] == INF) ? INF : fromSt[v2] + fromV2[v1] + fromV1[n];
	int ans = min(first, second);
	if (ans == INF) cout << -1;
	else cout << ans;
}
