#include <iostream>
#include <queue>

using namespace std;

auto comp = [](int a, int b) -> bool {
	if (abs(a) == abs(b)) return b < a;
	return abs(b) < abs(a);
	};

priority_queue<int, vector<int>, decltype(comp)> pq(comp);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}
