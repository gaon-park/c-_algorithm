#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> D;
vector<int> S;

int main() {
	int n;
	cin >> n;
	S.push_back(0); // idx 맞추기
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		S.push_back(tmp);
	}

	if (n == 1) {
		cout << S[1];
		return 0;
	}

	D.assign(n + 1, vector<int>(3, 0));
	D[1][1] = S[1], D[1][2] = 0;
	D[2][1] = S[2], D[2][2] = S[1] + S[2];

	for (int i = 3; i <= n; i++) {
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + S[i];
		D[i][2] = D[i - 1][1] + S[i];
	}

	cout << max(D[n][1], D[n][2]);
}