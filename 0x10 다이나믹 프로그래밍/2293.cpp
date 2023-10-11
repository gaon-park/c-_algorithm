#include <bits/stdc++.h>

using namespace std;

int n, k;
int coin[105];
int d[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> coin[i];

    d[0] = 1; // 합을 내야 하는 값이 동전의 가치와 같은 경우 +1 해주기 위해
    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            d[j] += d[j - coin[i]];
        }
    }

    cout << d[k];
}