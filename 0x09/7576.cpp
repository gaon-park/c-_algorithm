#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[1000][1000]; // 토마토판
int dist[1000][1000]; // 거리 겸 방문 판
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) Q.push({ i, j });
            else if (board[i][j] == 0) dist[i][j] = -1; // 안 익은 토마토
            // 익은 토마토랑 토마토 없는 곳은 0
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (dist[x][y] >= 0) continue;
            dist[x][y] = dist[cur.first][cur.second] + 1;
            Q.push({ x, y });
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 안 익은 토마토 등장
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;

    return 0;
}