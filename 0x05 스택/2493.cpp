#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> S;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		while (!S.empty() && S.top().second < tmp) {
			S.pop();
		}
		if (S.empty()) ans.push_back(0);
		else ans.push_back(S.top().first);
		S.push({ i + 1, tmp });
	}

	for (int i : ans) {
		cout << i << " ";
	}
}