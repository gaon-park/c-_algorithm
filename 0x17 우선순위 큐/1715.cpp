#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int ans = 0;
	while (!pq.empty()) {
		int first = pq.top(); pq.pop();
		int second = 0;
		if (!pq.empty()) {
			second = pq.top();
			pq.pop();
		}
		ans += (second == 0) ? 0 : first + second;
		if (!pq.empty()) pq.push(first + second);
	}

	cout << ans;
}
