#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b[n - i - 1] * a[i];
	}
	cout << ans;
}