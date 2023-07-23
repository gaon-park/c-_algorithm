#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> que = {};
    int n;
    cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.compare("push") == 0) {
            int x;
            cin >> x;
            que.push(x);
        } else if (s.compare("pop") == 0) {
            if (que.empty()) {
                ans += "-1\n";
            } else {
                ans += to_string(que.front()) + "\n";
                que.pop();
            }
        } else if (s.compare("size") == 0) {
            ans += to_string(que.size()) + "\n";
        } else if (s.compare("empty") == 0) {
            ans += (que.empty() ? "1\n" : "0\n");
        } else if (s.compare("front") == 0) {
            if (que.empty()) {
                ans += "-1\n";
            } else {
                ans += to_string(que.front()) + "\n";
            }
        } else if (s.compare("back") == 0) {
            if (que.empty()) {
                ans += "-1\n";
            } else {
                ans += to_string(que.back()) + "\n";
            }
        }
    }
    cout << ans;

    return 0;
}