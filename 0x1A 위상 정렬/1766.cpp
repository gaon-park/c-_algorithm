#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[32005];
int deg[32005];
priority_queue<int, vector<int>, greater<int>> pq; // 난이도가 쉬운 순

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // a번 문제는 b보다 먼저 풀어야 한다
		deg[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) pq.push(i);
	}

	vector<int> result;
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		result.push_back(cur);
		for (int i : adj[cur]) {
			deg[i]--;
			if (deg[i] == 0) {
				pq.push(i);
			}
		}
	}

	for (int i : result) {
		cout << i << " ";
	}
}
