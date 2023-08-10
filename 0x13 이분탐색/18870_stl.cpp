#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v1, uni; // unique

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
		uni.push_back(tmp);
	}
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end()); // 중복 제거 stl

	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), v1[i]) - uni.begin() << " ";
	}
}