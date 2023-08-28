#include <bits/stdc++.h>

using namespace std;

int n, q;
int cmd, x;
int cur; // 도현의 위치
int spot[500'005]; // 명소인가?
set<int> s; // 명소set

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> spot[i];
		if (spot[i] == 1) s.insert(i);
	}
	while (q--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			x--;
			if (spot[x]) { // 명소였다면, 지정 풀고
				spot[x] = 0;
				s.erase(x);
			}
			else { // 아니었다면, 명소 지정
				spot[x] = 1;
				s.insert(x);
			}
		}
		else if (cmd == 2) {
			cin >> x;
			cur = (cur + x) % n; // 시계방향으로 이동
		}
		else { // 다음 명소까지 몇 칸 이동해야 하는가?
			if (s.empty()) {
				cout << "-1\n";
				continue;
			}
			if (spot[cur]) {
				cout << "0\n";
				continue;
			}
			auto it = s.lower_bound(cur);
			if (it != s.end()) {
				cout << *it - cur << "\n";
			} else {
				cout << n - cur + *s.begin() << "\n";
			}
		}
	}
}