#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd.compare("pop") == 0) {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << s.size() << '\n';
		}
		else if (cmd.compare("empty") == 0) {
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
		}
		// top
		else {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << '\n';
		}
	}

	return 0;
}