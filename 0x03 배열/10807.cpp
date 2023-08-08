#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, v, a[101] = {}, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> v;
    for (int i = 0; i < n; i++) {
        if (a[i] == v) ans++;
    }
    cout << ans;
    
    return 0;
}