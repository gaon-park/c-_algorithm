#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> path;

void func() {
	if (path.size() >= m) {
		for (int i : path) cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		path.push_back(i);
		func();
		path.pop_back();
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
	func();
}