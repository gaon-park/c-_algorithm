#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> visited;

int rx[] = { -1, 0, 1, 0 };
int ry[] = { 0, 1, 0, -1 };

int bfs(int i, int j) {
    queue<pair<int, int>> que;
    que.push({ i, j });
    visited[i][j] = 1;
    int size = 0;

    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        size++;

        for (int i = 0; i < 4; i++) {
            int x = p.first + rx[i];
            int y = p.second + ry[i];
            if (x < 0 || y < 0 || x >= n || y >= m || v[x][y] != 1 || visited[x][y] == 1) continue;
            que.push({ x, y });
            visited[x][y] = 1;
        }
    }

    return size;
}

int main() {
    cin >> n >> m;
    visited.assign(n, vector<int>(m, 0));
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        vector<int> v1 = {};
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            v1.push_back(tmp);
            if (tmp == 1) que.push({ i, j });
        }
        v.push_back(v1);
    }

    int cnt = 0;
    int size = 0;
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        if (visited[p.first][p.second] == 0) {
            cnt++;
            size = max(size, bfs(p.first, p.second));
        }
    }

    cout << cnt << "\n" << size;

    return 0;
}