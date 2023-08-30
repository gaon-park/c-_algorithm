#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
priority_queue<int, vector<int>> maxQ;
priority_queue<int, vector<int>, greater<int>> minQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (maxQ.empty()) {
			maxQ.push(x);
			ans += to_string(x) + "\n";
			continue;
		}
		else if (minQ.empty()) {
			if (maxQ.top() > x) {
				minQ.push(maxQ.top()); maxQ.pop();
				maxQ.push(x);
			}
			else minQ.push(x);

			ans += to_string(maxQ.top()) + "\n";
			continue;
		}

		if (x > minQ.top()) {
			if (maxQ.size() <= minQ.size()) {
				maxQ.push(minQ.top()); minQ.pop();
			}
			minQ.push(x);
		}
		else if (x >= maxQ.top() && x <= minQ.top()) {
			if (maxQ.size() > minQ.size()) minQ.push(x);
			else maxQ.push(x);
		}
		else {
			if (maxQ.size() > minQ.size()) {
				minQ.push(maxQ.top()); maxQ.pop();
			}
			maxQ.push(x);
		}
		ans += to_string(maxQ.top()) + "\n";
	}

	cout << ans;
}
