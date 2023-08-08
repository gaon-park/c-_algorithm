#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans;
vector<vector<int>> board;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> brute;

int simulate() {
	int ans = 0;
	for (auto h : home) {
		int min_dis = n * 2;
		for (int i = 0; i < chicken.size(); i++) {
			if (!brute[i]) continue;
			int dis = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
			min_dis = min(min_dis, dis);
		}
		ans += min_dis;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 1) home.push_back({ i, j });
			else if (tmp == 2) chicken.push_back({ i, j });
		}
	}

	brute.assign(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	ans = 2 * n * home.size(); // 최대
	do {
		for (int i = 0; i < brute.size(); i++) {
			if (!brute[i]) continue;
			ans = min(ans, simulate());
		}
	} while (next_permutation(brute.begin(), brute.end()));

	cout << ans << "\n";
}