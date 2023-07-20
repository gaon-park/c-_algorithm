#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, s, y, man[6] = {}, woman[6] = {}, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s >> y;
        if (s == 0) woman[y - 1]++; // 여
        else man[y - 1]++; // 남
    }
    for (int i = 0; i < 6; i++) {
        ans += woman[i] / k + (woman[i] % k > 0 ? 1 : 0);
        ans += man[i] / k + (man[i] % k > 0 ? 1 : 0);
    }
    cout << ans;

    return 0;
}