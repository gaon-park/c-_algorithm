#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> stack = {};
    int sum = 0; // 더할 값
    int num = 1; // 곱할 값
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            num *= 2;
            stack.push(s[i]);
        }
        else if (s[i] == '[') {
            num *= 3;
            stack.push(s[i]);
        }
        else if (s[i] == ')') {
            if (stack.empty() || stack.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') sum += num; // 직전 괄호가 여는 괄호였다면
            stack.pop();
            num /= 2;
        }
        else if (s[i] == ']') {
            if (stack.empty() || stack.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') sum += num; // 직전 괄호가 여는 괄호였다면
            stack.pop();
            num /= 3;
        }
    }
    if (stack.empty()) cout << sum;
    else cout << 0;

    return 0;
}