#include <iostream>
#include <queue>

using namespace std;

int k;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> k;
		while (!q.empty()) q.pop(); // init

		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			q.push(x);
		}

		long long ans = 0;
		while (q.size() > 1) {
			long long first = q.top(); q.pop();
			long long second = q.top(); q.pop();
			ans += (first + second);
			q.push(first + second);
		}

		cout << ans << "\n";
	}
}
