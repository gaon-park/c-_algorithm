#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
int two[1'000'000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int idx = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two[idx++] = a[i] + a[j];
		}
	}
	sort(two, two + idx);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two, two + idx, a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
}