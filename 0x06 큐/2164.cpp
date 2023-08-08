#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> que = {};
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    while (que.size() > 1) {
        que.pop();
        if (que.size() == 1) break;
        int num = que.front();
        que.pop();
        que.push(num);
    }
    cout << que.front();

    return 0;
}