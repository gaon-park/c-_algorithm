#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end()); // O(NlgN)
	int ans = 0x7fffffff;
	int en = 0;
	for (int st = 0; st < n; st++) { // O(N)
		while (en < n && v[en] - v[st] < m) en++;
		if (en == n) break;
		ans = min(ans, v[en] - v[st]);
	}

	cout << ans;
}