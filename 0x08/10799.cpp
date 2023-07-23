#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int cnt = 0;
    stack<char> stack = {};
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(s[i]);
        } else {
            stack.pop();
            // 레이저
            if (i > 0 && s[i - 1] == '(') {
                cnt += stack.size();
            } 
            // 막대
            else {
                cnt++;
            }
        }
    }
    while (!stack.empty()) {
        cnt++;
        stack.pop();
    }

    cout << cnt;
    

    return 0;
}