#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> jewel[300003]; // {가격, 무게}
multiset<int> bag;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> jewel[i].second >> jewel[i].first;
	}
	sort(jewel, jewel + n);

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewel[i];
		auto it = bag.lower_bound(m); // 해당 무게를 담을 수 있는 가방 중 가장 작은 가방
		if (it == bag.end()) continue; // 최대무게가 m이상인 가방이 없음
		ans += v;
		bag.erase(it);
	}
	cout << ans;
}