#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 0x3f3f3f3f;
using namespace std;

int n, m; // 도시의 수, 도로의 수
int k; // 총 인원 수

int cost[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < 205; i++) {
		fill(cost[i], cost[i] + 205, INF);
		cost[i][i] = 0;
	}
	while (m--) {
		int a, b, t; // 출발 도시, 도착 도시, 걸리는 시간
		cin >> a >> b >> t;
		cost[a][b] = min(cost[a][b], t);
	}
	cin >> k;
	vector<int> person;
	for (int i = 0; i < k; i++) {
		int city;
		cin >> city;
		person.push_back(city);
	}

	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	vector<pair<int, int>> ans; // {max, city}
	// city 를 중심으로 모이고 퍼지는 시간 계산
	for (int city = 1; city <= n; city++) {
		int max_ = 0;
		bool flg = true;
		for (int p : person) {
			if (cost[p][city] == INF || cost[city][p] == INF) {
				flg = false;
				break;
			}
			max_ = max(max_, cost[p][city] + cost[city][p]);
		}
		if (flg) {
			ans.push_back({ max_, city });
		}
	}
	sort(ans.begin(), ans.end());
	int val = ans[0].first; // 최소
	for (auto p : ans) {
		if (p.first > val) break;
		cout << p.second << " ";
	}
}
