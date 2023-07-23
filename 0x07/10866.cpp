#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
	deque<int> deq = {};
	int n;
	cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("push_front") == 0) {
			int x;
			cin >> x;
			deq.push_front(x);
		}
		else if (cmd.compare("push_back") == 0) {
			int x;
			cin >> x;
			deq.push_back(x);
		}
		else if (cmd.compare("pop_front") == 0) {
			if (deq.empty()) {
				ans += "-1\n";
				continue;
			}
			ans +=to_string(deq.front()) + "\n";
			deq.pop_front();
		}
		else if (cmd.compare("pop_back") == 0) {
			if (deq.empty()) {
				ans += "-1\n";
				continue;
			}
			ans += to_string(deq.back()) + "\n";
			deq.pop_back();
		}
		else if (cmd.compare("size") == 0) {
			ans += to_string(deq.size()) + "\n";
		}
		else if (cmd.compare("empty") == 0) {
			ans += (deq.empty() ? "1\n" : "0\n");
		}
		else if (cmd.compare("front") == 0) {
			ans += (deq.empty() ? "-1\n" : to_string(deq.front()) + "\n");
		}
		// back
		else {
			ans += (deq.empty() ? "-1\n" : to_string(deq.back()) + "\n");
		}
	}
	cout << ans;

	return 0;
}