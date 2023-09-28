#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	// 절대값으로 정렬
	sort(vec.begin(), vec.end(), [](int& a, int& b) -> bool {
		int aa = abs(a);
		int bb = abs(b);
		return aa < bb;
		});

	int _min = 0x7fffffff;
	pair<int, int> ans;
	for (int i = 0; i < n - 1; i++) {
		int val = abs(vec[i] + vec[i + 1]);
		if (val < _min) {
			_min = val;
			ans = { min(vec[i], vec[i + 1]), max(vec[i], vec[i + 1]) };
		}
	}
	cout << ans.first << " " << ans.second;
}
