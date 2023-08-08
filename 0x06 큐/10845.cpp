#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	queue<int> Q = {};
	int n;
	cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.compare("push") == 0) {
			int x;
			cin >> x;
			Q.push(x);
		}
		else if (s.compare("pop") == 0) {
			if (Q.empty()) ans += "-1\n";
			else {
				ans += to_string(Q.front()) + "\n";
				Q.pop();
			}
		}
		else if (s.compare("size") == 0) {
			ans += to_string(Q.size()) + "\n";
		}
		else if (s.compare("empty") == 0) {
			ans += (Q.empty() ? "1\n" : "0\n");
		}
		else if (s.compare("front") == 0) {
			ans += (Q.empty() ? "-1" : to_string(Q.front())) + "\n";
		}
		// back
		else {
			ans += (Q.empty() ? "-1" : to_string(Q.back())) + "\n";
		}
	}

	cout << ans;

	return 0;
}