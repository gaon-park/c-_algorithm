#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> path;

void func(int idx) {
	if (idx >= m) {
		for (int i : path) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (path.empty() || path.back() <= i) {
			path.push_back(i);
			func(idx + 1);
			path.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	func(0);
}