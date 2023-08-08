#include <bits/stdc++.h>

using namespace std;

int n;
vector<long> card;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long m;
		cin >> m;
		card.push_back(m);
	}

	sort(card.begin(), card.end());
	long long p = 0, q = -1, q_val = 0;
	for (int i = 0; i < card.size(); i++) {
		if (i == 0 || card[i - 1] == card[i]) p++;
		else {
			if (p > q) {
				q = p;
				q_val = card[i - 1];
			}
			p = 1;
		}
	}
	if (p > q) q_val = card[n - 1];
	cout << q_val;
}