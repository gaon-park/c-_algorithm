#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<vector<int>> s; // num, idx, cnt
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		while (!s.empty() && s.top()[0] <= tmp) {
			auto v = s.top();
			s.pop();
			ans += v[2];
			if (!s.empty()) {
				s.top()[2] += 1 + v[2];
			}
		}
		s.push({ tmp, i, 0 });
	}

	while (!s.empty()) {
		auto v = s.top();
		s.pop();
		ans += v[2];
		if (!s.empty()) {
			s.top()[2] += 1 + v[2];
		}
	}

	cout << ans;
}