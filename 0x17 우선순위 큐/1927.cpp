#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int num;
		cin >> num;
		if (num > 0) {
			pq.push(num);
		}
		else {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}
