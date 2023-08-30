#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
bool isused[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// bfs
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (isused[i]) continue;
		num++;
		queue<int> q;
		q.push(i);
		isused[i] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto next : adj[cur]) {
				if (isused[next]) continue;
				q.push(next);
				isused[next] = true;
			}
		}
	}
	cout << num;
}