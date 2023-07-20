#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int m;
    cin >> s >> m;
    list<char> L;
    for (char c : s) L.push_back(c);
    list<char>::iterator it = L.end();

    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'P') {
            char add;
            cin >> add;
            L.insert(it, add);
        } else if (op == 'L') {
            if (it != L.begin()) it--;
        } else if (op == 'D') {
            if (it != L.end()) it++;
        } else {
            if (it != L.begin()) {
                it--;
                it = L.erase(it);
            }
        }

    }

    for (auto i : L) {
        cout << i;
    }

    return 0;
}