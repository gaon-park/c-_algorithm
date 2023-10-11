#include <bits/stdc++.h>

using namespace std;

int n;
int t[1500005];
int p[1500005];
int d[1500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    for (int i = n; i >= 1; i--)
        d[i] = max(
            i + t[i] <= n + 1 ? d[i + t[i]] + p[i] : d[i + 1], // 오늘 일을 할 때 얻을 수 있는 최고 수익
            d[i + 1] // 오늘 일을 하지 않았을 때 얻을 수 있는 최고 수익
        );
    cout << d[1];
}