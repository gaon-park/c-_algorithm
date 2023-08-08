#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<pair<int, int>> S;
    int N;
    long long ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        
        int cnt = 1;
        while (!S.empty() && S.top().first <= tmp) {
            ans += S.top().second;
            if (S.top().first == tmp) cnt += S.top().second;
            S.pop();
        }
        if (!S.empty()) ans++;
        S.push({tmp, cnt});
    }

    cout << ans << "\n";
}
