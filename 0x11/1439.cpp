#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	
	int cnt[2] = {};
	cnt[s[0] - '0']++;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) cnt[s[i] - '0']++;
	}
	cout << min(cnt[0], cnt[1]);
}