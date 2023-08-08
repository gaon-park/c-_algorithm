#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 'a'; i <= 'z'; i++) {
        int cnt = 0;
        for (char c : s) {
            if (c == i)  cnt++;
        }
        cout << cnt << ' '; 
    }

    return 0;
}