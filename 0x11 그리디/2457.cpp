#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> flower;
	for (int i = 0; i < n; i++) {
		int open_m, open_d, close_m, close_d;
		cin >> open_m >> open_d >> close_m >> close_d;
		flower.push_back({ open_m * 100 + open_d, close_m * 100 + close_d });
	}

	int ans = 0, now = 301;
	while (now < 1201) {
		int next = now;
		for (int i = 0; i < flower.size(); i++) {
			if (flower[i].first <= now && flower[i].second > next) {
				next = flower[i].second;
			}
		}
		if (next == now) {
			cout << 0;
			return 0;
		}
		ans++;
		now = next;
	}
	cout << ans;
}