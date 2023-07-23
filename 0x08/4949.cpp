#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ans = "";
    while (true) {
        string s;
        cin.ignore();
        getline(cin, s, '.');
        if (s.length() == 0) {
            break;
        }

        stack<char> S = {};
        bool flg = true;
        for (char c : s) {
            if (c == '(' || c == '[') {
                S.push(c);
            } else if (c == ')') {
                if (!S.empty() && S.top() == '(') S.pop();
                else {
                    flg = false;
                    break;
                }
            } else if (c == ']') {
                if (!S.empty() && S.top() == '[') S.pop();
                else {
                    flg = false;
                    break;
                }
            }
        }
        if (!S.empty()) flg = false;
        ans += (flg ? "yes\n" : "no\n");
    }

    cout << ans;

    return 0;
}