#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> vec;
		cin >> n;
		for (int i = 0; i < n; i++) {
			long tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}

		long price = vec[vec.size() - 1];
		long ans = 0;
		for (int i = vec.size() - 2; i >= 0; i--) {
			if (price > vec[i]) {
				ans += (price - vec[i]);
			} else if (price < vec[i]) {
				price = vec[i];
			}
		}
		
		cout << ans << "\n";
	}
}