#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v1, v2, uni; // unique

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end()); // 중복 제거 배열
	for (int i = 0; i < n; i++) {
		if (i == 0 || v2[i - 1] != v2[i]) 
			uni.push_back(v2[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), v1[i]) - uni.begin() << " ";
	}
}