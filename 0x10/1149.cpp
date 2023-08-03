#include <bits/stdc++.h>

using namespace std;

int n;
int D[1000][3];
int cost[1000][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	D[0][0] = cost[0][0], D[0][1] = cost[0][1], D[0][2] = cost[0][2];
	for (int i = 1; i < n; i++) {
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + cost[i][0];
		D[i][1] = min(D[i - 1][0], D[i - 1][2]) + cost[i][1];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + cost[i][2];
	}
	cout << min(min(D[n - 1][0], D[n - 1][1]), D[n - 1][2]);
}