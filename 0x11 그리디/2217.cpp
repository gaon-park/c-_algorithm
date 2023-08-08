#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int max_weight = 0;
	for (int i = 0; i < n; i++) {
		int weight = v[i] * (n - i);
		max_weight = max(max_weight, weight);
	}
	cout << max_weight;
}