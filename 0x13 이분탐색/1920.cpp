#include <bits/stdc++.h>

using namespace std;

int n;
int a[100'000];

int binary_search(int num) {
	int st = 0, en = n - 1;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (a[mid] == num) return 1;
		else if (a[mid] < num) {
			st = mid + 1;
		} else {
			en = mid - 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		cout << binary_search(num) << "\n";
	}
}