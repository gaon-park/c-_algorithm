#include <iostream>
#include <algorithm>

using namespace std;

int input[500][500];
int d[500][500];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input[i][j];
		}
	}

	d[0][0] = input[0][0];
	int ans = d[0][0];
	for (int i = 1; i < n; i++) { 
		for (int j = 0; j <= i; j++) {
			if (j == 0) d[i][j] = d[i - 1][j] + input[i][j];
			else {
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + input[i][j];
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
}
