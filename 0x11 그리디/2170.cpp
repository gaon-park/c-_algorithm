#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> vec; // {x, y}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.assign(n, pair<int, int>());
    for (int i = 0; i < n; i++) 
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    int st, en;
    tie(st, en) = vec[0];
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int a, b;
        tie(a, b) = vec[i];
        if (a <= en && en <= b) // 앞의 선과 겹치는 부분이 있으면 오른쪽 방향으로 확장
            en = max(en, b);
        else if (en < a) { // 겹치지 않는다면 현재 길이를 더하고, 새로운 선으로 변경
            sum += (en - st);
            st = a;
            en = b;
        }
    }
    cout << sum + en - st;
}