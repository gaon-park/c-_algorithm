#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (n--) {
		long long x;
		cin >> x;
		pq.push(x);
	}

	while (m--) {
		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans;
}