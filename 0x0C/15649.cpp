#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[8], ans[8];
void func(int depth) {
	if (depth >= m) {
		for (int i = 0; i < depth; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			ans[depth] = i + 1;
			func(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	func(0);
}