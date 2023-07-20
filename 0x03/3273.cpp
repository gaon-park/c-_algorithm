#include <bits/stdc++.h>
using namespace std;

int a[100001]{};
int occur[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (x - a[i] > 0 && occur[x - a[i]]) ans++;
        occur[a[i]] = true;
    }
    cout << ans;
    
    return 0;
}