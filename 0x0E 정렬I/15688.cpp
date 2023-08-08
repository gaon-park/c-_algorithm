#include <bits/stdc++.h>

using namespace std;

int n;
int freq[20000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		freq[tmp + 1'000'000]++;
	}

	for (int i = 0; i <= 2'000'000; i++) {
		while (freq[i]--) {
			cout << i - 1'000'000 << "\n";
		}
	}
}