#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	sort(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n - i) * p[i];
	}
	cout << ans;
}