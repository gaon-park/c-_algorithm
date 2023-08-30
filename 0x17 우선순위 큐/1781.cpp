#include <iostream>
#include <queue>

using namespace std;

// {데드라인, 컵라면수}
auto comp = [](pair<int, long long>& p, pair<int, long long>& q) -> bool {
	if (p.second == q.second) return q.first < p.first;
	return p.second < q.second;
	};

int n;
int isused[200'001];
priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(comp)> Q(comp);

int find_empty(int idx) {
	if (isused[idx] == 0) return -1;
	if (isused[idx] == idx) {
		isused[idx] = isused[idx - 1];
		return idx;
	}
	return isused[idx] = find_empty(isused[idx]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		isused[i] = i; // init
	}
	while (n--) {
		int d, c;
		cin >> d >> c;
		Q.push({ d, c });
	}

	long long ans = 0;
	while (!Q.empty()) {
		auto p = Q.top(); Q.pop();
		int idx = find_empty(p.first);
		if (idx <= 0) continue;
		ans += p.second;
	}

	cout << ans;
}
