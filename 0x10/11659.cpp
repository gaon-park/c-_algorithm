#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		int tmp; 
		cin >> tmp;
		v.push_back(v[i - 1] + tmp);
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << v[j] - v[i - 1] << "\n";
	}
}