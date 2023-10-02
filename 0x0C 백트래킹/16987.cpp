#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> eggs;
int ans;

void update_ans() {
	int cnt = 0;
	for (auto p : eggs) {
		if (p.first <= 0) cnt++;
	}
	ans = max(ans, cnt);
}

void solve(int left) {
	if (left == n) {
		int x = 0;
		return;
	}

	if (eggs[left].first <= 0) solve(left + 1);
	else {
		int left_origin = eggs[left].first;
		int right_origin;
		for (int i = 0; i < n; i++) {
			if (i == left) continue;
			if (eggs[i].first > 0) {
				right_origin = eggs[i].first;
				eggs[left].first -= eggs[i].second;
				eggs[i].first -= eggs[left].second;
				update_ans();
				solve(left + 1);
				eggs[left].first = left_origin;
				eggs[i].first = right_origin;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int hp, weight;
		cin >> hp >> weight;
		eggs.push_back({ hp, weight });
	}
	
	solve(0);
	cout << ans;
}
