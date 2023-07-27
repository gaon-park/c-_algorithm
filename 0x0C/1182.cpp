#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0;
int arr[20];

void func(int sum, int cur) {
	if (cur == n) {
		if (sum == s) cnt++;
		return;
	}
	func(sum, cur + 1);
	func(sum + arr[cur], cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}