#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        list<char> L = {};
        auto it = L.begin();
        for (char c : s) {
            if (c == '-' && it != L.begin()) {
                it--;
                it = L.erase(it);
            }
            else if (c == '<' && it != L.begin()) it--;
            else if (c == '>' && it != L.end()) it++;
            else if (c != '-' && c != '<' && c != '>') L.insert(it, c);
        }
        for (char c : L) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}