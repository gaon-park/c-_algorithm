#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), [](pair<int, int> p, pair<int, int> q) -> bool {
		if (p.second == q.second) return p.first < q.first;
		return p.second < q.second;
		});

	int cnt = 1;
	int end_time = v[0].second;
	for (int i = 1; i < n; i++) {
		// 진행중인 회의 없음, 새 회의 시작 가능
		if (end_time <= v[i].first) {
			cnt++;
			end_time = v[i].second;
		}
	}

	cout << cnt;
}