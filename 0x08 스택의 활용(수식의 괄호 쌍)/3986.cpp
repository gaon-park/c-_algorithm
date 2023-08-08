#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<char> S = {};
        for (char c : s) {
            if (S.empty() || S.top() != c) S.push(c);
            else if (S.top() == c) S.pop();
        }
        if (S.empty()) cnt++;
    }
    cout << cnt;

    return 0;
}