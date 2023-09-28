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
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end()); // 정렬
	
	int ans = 0x7fffffff;
	int st = 0, en = n - 1;
	while (st < en) {
		int val = vec[st] + vec[en];
		if (abs(val) < abs(ans)) { // 더 줄일 수 있음
			ans = val;
		}
		if (val < 0) {
			st++;
		}
		else {
			en--;
		}
	}

	cout << ans;
}
