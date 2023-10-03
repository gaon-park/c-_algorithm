#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> d; // i 번째 건물을 짓는데 필요한 시간
vector<int> indeg; // i 번째 건물을 짓기 위해 지어져 있어야 하는 건물의 수
vector<vector<int>> after; // i 번째 건물을 지으면 지을 수 있는 건물의 인덱스 리스트
int w;

void solve() {
    vector<int> total;
    cin >> n >> k;
    d.assign(n, 0);
    indeg.assign(n, 0);
    after.assign(n, vector<int>());
    total.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        indeg[y - 1]++;
        after[x - 1].push_back(y - 1);
    }
    cin >> w;
    --w;

    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int nxt : after[cur]) {
            total[nxt] = max(total[nxt], d[cur] + total[cur]);
            indeg[nxt]--;
            if (indeg[nxt] == 0) Q.push(nxt);
        }
    }
    cout << total[w] + d[w] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
