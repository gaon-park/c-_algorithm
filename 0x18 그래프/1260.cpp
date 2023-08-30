#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<int> adj[1005];
int isused[1005];

void bfs() {
	queue<int> q;
	q.push(v);
	isused[v] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int next : adj[cur]) {
			if (isused[next]) continue;
			isused[next] = 1;
			q.push(next);
		}
	}
	cout << "\n";
}

void dfs(int cur) {
	isused[cur] = 1;
	cout << cur << " ";
	for (int i : adj[cur]) {
		if (isused[i]) continue;
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for (int i = 0; i <= n; i++) sort(adj[i].begin(), adj[i].end());

	dfs(v);
	cout << "\n";
	fill(isused, isused + 1005, 0);
	bfs();
}