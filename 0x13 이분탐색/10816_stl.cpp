#include <bits/stdc++.h>

using namespace std;

int n;
int card[500'000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> card[i];
	sort(card, card + n);

	int m;
	cin >> m;
	while (m--) {
		int target;
		cin >> target;
		cout << upper_bound(card, card + n, target) - lower_bound(card, card + n, target) << " ";
	}
}