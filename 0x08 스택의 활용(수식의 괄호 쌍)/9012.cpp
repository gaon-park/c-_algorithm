#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string ans = "";
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        stack<char> S = {};
        bool flg = true;
        for (char c : s) {
            if (c == '(' || c == '[') S.push(c);
            else if (c == ')' && !S.empty() && S.top() == '(') S.pop();
            else if (c == ']' && !S.empty() && S.top() == '[') S.pop();
            else {
                flg = false;
                break;
            }
        }
        if (!S.empty()) flg = false;
        ans += (flg ? "YES\n" : "NO\n");
    }
    cout << ans;

    return 0;
}