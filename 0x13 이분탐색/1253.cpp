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

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int val = vec[i] - vec[j];
			int l = lower_bound(vec.begin(), vec.end(), vec[i] - vec[j]) - vec.begin();
			bool res = false;
			while (l < n && vec[l] == val) {
				if (l != i && l != j) {
					res = true;
					break;
				}
				l++;
			}
			if (res) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}
