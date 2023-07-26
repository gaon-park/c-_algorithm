#include <bits/stdc++.h>
using namespace std;

int N, board[64][64];

bool check(int x, int y, int w) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + w; j++) {
            if (board[i][j] != board[x][y]) return false;
        }
    }
    return true;
}

void solve(int x, int y, int w) {
    if (check(x, y, w)) {
        cout << board[x][y];
        return;
    }

    cout << "(";
    int half = w / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            solve(x + half * i, y + half * j, half);
        }
    }
    cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            board[i][j] = int(c - '0');
        }
    }

    solve(0, 0, N);
}