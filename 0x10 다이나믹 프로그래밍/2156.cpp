#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10005];
int dp[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> wine[i];
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for (int i = 3; i <= n; i++) {
        // 1. dp[i - 1]: 이번 와인을 먹지 않고 넘길 때
        // 2. wine[i] + dp[i - 2]: 이번 와인을 먹는데, 연속된 와인 중 첫 번째로 먹을 때
        // 3. wine[i] + wine[i - 1] + dp[i - 3]: 이번 와인을 먹는데, 연속된 와인 중 두 번째로 먹을 때
        dp[i] = max({dp[i - 1], wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 3]});
    }
    cout << dp[n];
}