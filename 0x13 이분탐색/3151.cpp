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
	
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			auto u = upper_bound(vec.begin() + j + 1, vec.end(), -vec[i] - vec[j]);
			auto l = lower_bound(vec.begin() + j + 1, vec.end(), -vec[i] - vec[j]);
			ans += u - l; // 중간에 같은 수가 있다면, 그 개수도 다 더해야 함
		}
	}

	cout << ans;
}
