#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> adj[1005];
vector<int> isused;

void dfs(pair<int, int> cur, int to) {
	if (cur.first == to) {
		cout << cur.second << "\n";
		return;
	}
	for (auto next : adj[cur.first]) {
		if (isused[next.first]) continue;
		isused[next.first] = 1;
		dfs({ next.first, next.second + cur.second }, to);
		if (next.first == to) break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v, d });
		adj[v].push_back({ u, d });
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		isused.assign(n + 1, 0);
		isused[u] = 1;
		dfs({ u, 0 }, v);
	}
}
