#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int num[10]{};
    int n = a * b * c;
    while (n > 0) {
        num[n % 10]++;
        n /= 10;
    }
    for (int i : num) cout << i << '\n';

    return 0;
}