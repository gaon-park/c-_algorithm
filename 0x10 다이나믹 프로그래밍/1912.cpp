#include <iostream>
#include <algorithm>

using namespace std;

int input[100'001];
int d[100'001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		d[i] = input[i];
	}

	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + input[i], d[i]);
	}

	cout << *max_element(d, d + n);
}
