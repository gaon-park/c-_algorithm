#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end(), greater<int>());
	stack<int> S;
	stack<int> minus;
	int ans = 0;
	for (int i = 0; i < n && vec[i] > 0; i++) {
		if (S.empty() && vec[i] > 1) {
			S.push(vec[i]);
		} else if (!S.empty() && vec[i] > 1) {
			ans += S.top() * vec[i];
			S.pop();
		} else {
			ans += vec[i];
		}
	}

	for (int i = n - 1; i >= 0 && vec[i] <= 0; i--) {
		if (minus.empty()) minus.push(vec[i]);
		else {
			ans += minus.top() * vec[i];
			minus.pop();
		}
	}
	if (!minus.empty()) ans += minus.top();
	if (!S.empty()) ans += S.top();

	cout << ans;
}