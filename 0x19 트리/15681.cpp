#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> adj[100'005];
vector<bool> isused(100'005);
vector<int> subTreeCnt(100'005);

int countSubtreeNode(int cur) {
	isused[cur] = true;
	for (int next : adj[cur]) {
		if (isused[next]) continue;
		subTreeCnt[cur] += countSubtreeNode(next);
	}
	subTreeCnt[cur]++; // 자기 자신
	return subTreeCnt[cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	countSubtreeNode(r);
	while (q--) {
		int u;
		cin >> u;
		cout << subTreeCnt[u] << "\n";
	}
}
