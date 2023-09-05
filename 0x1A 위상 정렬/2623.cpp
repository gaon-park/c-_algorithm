#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; // 가수의 수, 보조 PD의 수
vector<int> adj[1005];
int deg[1005]; // 들어오는 간선의 수
vector<int> result; // 결과

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int prev = 0;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			deg[tmp] += (prev == 0 ? 0 : 1);
			adj[prev].push_back(tmp);
			prev = tmp;
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);

		for (int next : adj[cur]) {
			deg[next]--;
			if (deg[next] == 0) q.push(next);
		}
	}

	if (result.size() < n) { // n명을 다 뽑지 못했다
		cout << "0\n";
	}
	else { // 다 뽑았다
		for (int i : result) {
			cout << i << "\n";
		}
	}
}
