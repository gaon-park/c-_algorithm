#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	unordered_map<string, int> nameMap;
	string arr[100'000] = {};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		nameMap[arr[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') { // is digit
			cout << arr[stoi(s)] << "\n";
		} else {
			cout << nameMap[s] << "\n";
		}
	}
}