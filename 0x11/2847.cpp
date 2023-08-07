#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int cnt = 0;
	for (int i = n - 2; i >= 0; i--) {
		// 지금 레벨이, 다음 레벨보다 점수를 많이 주는 경우
		if (v[i + 1] <= v[i]) {
			cnt += (v[i] - v[i + 1] + 1);
			v[i] = v[i + 1] - 1;
		}
	}
	cout << cnt;
}