#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	vector<int> v;
	vector<int> tmp;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		if (i <= m) tmp.push_back(1);
		else tmp.push_back(0);
	}

	do {
		for (int i = 0; i < n; i++) {
			if (tmp[i]) {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
	} while (prev_permutation(tmp.begin(), tmp.end()));
}