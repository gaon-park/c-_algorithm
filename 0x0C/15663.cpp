#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v, path, isused;

void func() {
	if (path.size() >= m) {
		for (int i : path) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (i > 0 && v[i] == v[i - 1] && !isused[i - 1]) continue;
		if (!isused[i]) {
			isused[i] = 1;
			path.push_back(v[i]);
			func();
			path.pop_back();
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		isused.push_back(0);
	}
	sort(v.begin(), v.end());
	func();
}