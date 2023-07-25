#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> MAP;
vector<vector<int>> visited;

int rx[] = { -1, 0, 1, 0 };
int ry[] = { 0, 1, 0, -1 };

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v.push_back(s[j] - '0');
        }
        MAP.push_back(v);
    }

    visited.assign(n, vector<int>(m, 0));
    queue<tuple<int, int, int>> que;
    que.push({ 0, 0, 1 });
    visited[0][0] = 1;

    int dist = INT_MAX;

    while (!que.empty()) {
        tuple t = que.front();
        int distance = get<2>(t);
        que.pop();

        if (get<0>(t) == n - 1 && get<1>(t) == m - 1) {
            dist = min(dist, distance);
        }

        for (int i = 0; i < 4; i++) {
            int x = get<0>(t) + rx[i];
            int y = get<1>(t) + ry[i];
            if (x < 0 || y < 0 || x >= n || y >= m || MAP[x][y] != 1 || visited[x][y] != 0) continue;
            que.push({ x, y, distance + 1 });
            visited[x][y] = 1;
        }
    }

    cout << dist;

    return 0;
}