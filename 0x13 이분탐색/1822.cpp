#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int na, nb;
set<int> a, b, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> na >> nb;
	for (int i = 0; i < na; i++) {
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0; i < nb; i++) {
		int tmp;
		cin >> tmp;
		b.insert(tmp);
	}
	for (int i : a) {
		if (b.count(i)) continue;
		ans.insert(i);
	}

	cout << ans.size() << "\n";
	if (!ans.empty()) {
		for (int i : ans) {
			cout << i << " ";
		}
	}
}
