#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		long long ans = 0;
		stack<pair<long long, long long>> s;
		for (int i = 0; i < n; i++) {
			long long h;
			cin >> h;
			long long cnt = 0; // 현재 입력된 높이를 push 하기 위해 몇개 pop되었는가?
			while (!s.empty() && s.top().first >= h) { // 현재 입력된 높이가 작을 때까지 pop
				auto p = s.top(); s.pop();
				ans = max(ans, p.second + p.first * cnt);
				cnt += (p.second) / p.first; // pop하는 높이를 입력했을 때 몇개 pop했었는가?
			}
			if (h != 0) 
				s.push({ h, h * (cnt + 1) });
		}

		// 남은 블럭 계산
		long long cnt = 0;
		while (!s.empty()) {
			auto p = s.top(); s.pop();
			ans = max(ans, p.second + p.first * cnt);
			cnt += p.second / p.first;
		}

		cout << ans << "\n";
	}
}
