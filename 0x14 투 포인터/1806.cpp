#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int en = 0, sum = v[0], ans = 0x7fffffff;
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) {
			en++;
			if (en != n) sum += v[en];
		}
		if (en == n) break;
		ans = min(ans, en - st + 1);
		sum -= v[st];
	}
	cout << (ans == 0x7fffffff ? 0 : ans); 
}