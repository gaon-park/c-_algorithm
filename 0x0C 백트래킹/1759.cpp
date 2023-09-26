#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> vec;
deque<char> path;
vector<int> isused;
unordered_set<char> aeiou = { 'a', 'e', 'i', 'o', 'u' };

void solve(int dep) {
    if (dep == L) {
        int cnt = 0;
        for (auto it = path.begin(); it != path.end(); it++) {
            cnt += aeiou.count(*it);
        }
        if (cnt >= 1 && cnt <= L - 2) {
            for (auto it = path.begin(); it != path.end(); it++) {
                cout << *it;
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 0; i < C; i++) {
        if (isused[i]) continue;
        if (!path.empty() && path.back() > vec[i]) continue;
        isused[i] = 1;
        path.push_back(vec[i]);
        solve(dep + 1);
        path.pop_back();
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        vec.push_back(c);
    }
    isused.assign(C, 0);
    sort(vec.begin(), vec.end());
    solve(0);
}