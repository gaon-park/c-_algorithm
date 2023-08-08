#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a, b;
		while (n--) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		while (m--) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());

		int i = 0, j = 0;
		int cnt = 0;
		while (i < a.size() && j < b.size()) {
			while (a[i] <= b[j]) j++;
			if (j < b.size()) {
				cnt += b.size() - j;
			}
			i++;
		}

		cout << cnt << "\n";
	}
}