#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		multiset<int> ms;
		while (k--) {
			char cmd;
			int num;
			cin >> cmd >> num;
			if (cmd == 'D') {
				if (ms.empty()) continue;
				if (num == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			} else {
				ms.insert(num);
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
	}
}