#include <bits/stdc++.h>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
char board[1000][1000];
int dist[1000][1000];
int s_dist[1000][1000];
int w, h;

void bfs1(queue<pair<int, int>> Q) {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || y < 0 || x >= h || y >= w) continue;
            if (dist[x][y] >= 0 || board[x][y] == '#') continue; // 이미 불이 번졌거나, 갈 수 없는 공간
            Q.push({ x, y });
            dist[x][y] = dist[cur.first][cur.second] + 1;
        }
    }
}

void bfs2(queue<pair<int, int>> Q) {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            // 범위를 벗어났다는 것은 탈출에 성공했다는 의미
            if (x < 0 || y < 0 || x >= h || y >= w) {
                cout << s_dist[cur.first][cur.second] + 1 << "\n";
                return;
            }
            if (s_dist[x][y] >= 0 || board[x][y] == '#') continue;
            if (dist[x][y] != -1 && dist[x][y] <= s_dist[cur.first][cur.second] + 1) continue;
            // 불이 번지지 않은 빈공간
            Q.push({ x, y });
            s_dist[x][y] = s_dist[cur.first][cur.second] + 1;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            fill(dist[i], dist[i] + w, -1);
            fill(s_dist[i], s_dist[i] + w, -1);
        }
        queue<pair<int, int>> Q;
        queue<pair<int, int>> Q2;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '*') {
                    Q.push({ i, j });
                    dist[i][j] = 0;
                }
                else if (board[i][j] == '@') {
                    Q2.push({ i, j });
                    s_dist[i][j] = 0;
                }
            }
        }

        bfs1(Q);
        bfs2(Q2);
    }

    return 0;
}
