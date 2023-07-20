#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> stack = {};
    int num = 1;
    string s;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        while (num <= tmp) {
            stack.push(num++);
            s += "+\n";
        }
        if (stack.top() != tmp) {
            cout << "NO\n";
            return 0;
        }
        stack.pop();
        s += "-\n";
    }
    cout << s;

    return 0;
}