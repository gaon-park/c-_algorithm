#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> path;

void func(int idx, int next) {
	if (idx >= m) {
		for (int i : path) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = next; i <= n; i++) {
		path.push_back(i);
		func(idx + 1, i + 1);
		path.pop_back();
	}
}

int main() {
	cin >> n >> m;
	func(0, 1);
}