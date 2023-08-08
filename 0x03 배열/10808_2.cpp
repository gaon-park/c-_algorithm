#include <bits/stdc++.h>
using namespace std;

int freq['z' - 'a' + 1];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (auto c : s) {
        freq[c - 'a']++;
    }
    for (int n : freq)
        cout << n << ' ';

    return 0;
}