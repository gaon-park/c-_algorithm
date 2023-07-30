#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v, isused;
vector<int> path;

void func(int idx) {
	if (idx >= m) {
		for (int i : path) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			path.push_back(v[i]);
			func(idx + 1);
			isused[i] = 0;
			path.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	isused.assign(n, 0);

	func(0);
}