#include <bits/stdc++.h>

using namespace std;

vector<int> D;

int main() {
	D.assign(12, 0);
	D[1] = 1, D[2] = 2, D[3] = 4;
	for (int i = 4; i <= 11; i++) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << D[n] << "\n";
	}
}