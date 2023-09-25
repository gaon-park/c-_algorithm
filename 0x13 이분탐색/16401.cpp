#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> snack;

bool solve(int s) {
	if (s == 0) return true;
	int cnt = 0;
	for (int t : snack) {
		cnt += t / s;
	}
	return cnt >= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		snack.push_back(t);
	}

	int ans = 0;
	int st = 0, en = 1000000000;
	while (st < en) {
		int mid = (st + en) / 2;
		if (solve(mid)) {
			ans = max(ans, mid);
			st = mid + 1;
		}
		else {
			en = mid;
		}
	}

	cout << ans;
}
