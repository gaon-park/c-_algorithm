#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> room; // 앞 강의가 끝난 시간
	room.push(v[0].second);

	int cnt = 1; // 일단 한 개는 무조건 필요
	for (int i = 1; i < n; i++) {
		if (room.top() <= v[i].first) { // 끝나는 동시에 시작 가능이면
			int cur = room.top();
			room.pop();
			room.push(v[i].second);
		} else { // 강의실 하나 더 필요
			room.push(v[i].second);
		}
		cnt = max(cnt, int(room.size()));
	}
	cout << cnt;
}