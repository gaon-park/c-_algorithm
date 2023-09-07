#include <iostream>
#include <string>

using namespace std;

string a, b;
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) { // 문자가 같을 때
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 문자가 같지 않을 때
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.size()][b.size()];
}
