#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int board[1005][1005];
int isused[1005][1005][15];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = tmp[j - 1] - '0';
        }
    }
            
    queue<tuple<int, int, int>> Q;
    Q.push({ 1, 1, 0 });
    isused[1][1][0] = 1;
    while (!Q.empty()) {
        auto [cx, cy, cw] = Q.front(); Q.pop();
        if (cx == n && cy == m) {
            cout << isused[cx][cy][cw];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x = cx + dx[i];
            int y = cy + dy[i];
            if (x < 1 || y < 1 || x > n || y > m) continue;

            int wb = cw; // 부순 횟수
            if (board[x][y]) wb++;
            if (wb > k || isused[x][y][wb]) continue;
            isused[x][y][wb] = isused[cx][cy][cw] + 1;
            Q.push({ x, y, wb });
        }
    }

    cout << -1;
}