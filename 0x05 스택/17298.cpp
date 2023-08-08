#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> input = {};
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        input.push(tmp);
    }
    stack<int> s = {};
    stack<int> ans = {};
    while (!input.empty()) {
        int cur = input.top();
        input.pop();
        // 자기보다 큰 수 나올 때까지 pop
        while (!s.empty() && cur >= s.top()) {
            s.pop();
        }
        // 오큰수 없음
        if (s.empty()) {
            ans.push(-1);
        }
        // 오큰수 있음
        else {
            ans.push(s.top());
        }
        s.push(cur);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}