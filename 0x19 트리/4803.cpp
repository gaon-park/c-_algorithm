#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> isused;
int cnt;
bool isTree;

void dfs(int cur, int prev) {
	for (int next : v[cur]) {
		if (next == prev) continue;
		if (isused[next]) {
			isTree = false;
			continue;
		}
		isused[next] = 1;
		dfs(next, cur);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		v.assign(n + 1, vector<int>());
		isused.assign(n + 1, 0);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (isused[i]) continue;
			isused[i] = 1;
			isTree = true;
			dfs(i, -1);
			cnt += isTree;
		}

		cout << "Case " << tc++ << ": ";
		if (cnt == 0) cout << "No trees.\n";
		else if (cnt == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";
	}
}
