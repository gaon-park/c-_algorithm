#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int arr[30001];
unordered_map<int, int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int en = 0, cnt = 1;
	int ans = 0;
	s[arr[0]] = 1;
	for (int st = 0; st < n; st++) {
		while (cnt < k) {
			en++;
			cnt++;
			if (en >= n) en %= n;
			if (s.count(arr[en]) > 0) {
				s[arr[en]]++;
			}
			else {
				s[arr[en]] = 1;
			}
		}
		ans = max(ans, int(s.size()) + (s.count(c) ? 0 : 1));
		if (s[arr[st]] > 1) s[arr[st]]--;
		else s.erase(arr[st]);
		cnt--;
	}

	cout << ans;
} 