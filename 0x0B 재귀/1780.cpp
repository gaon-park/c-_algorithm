#include <bits/stdc++.h>
using namespace std;

int n;
int board[2200][2200];
int ans[3]; // 0, 1, 2

// 해당 종이 내부에 같은 숫자로만 채워져있는지 확인
bool check(int x, int y, int w) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + w; j++) {
            if (board[i][j] != board[x][y]) return false;
        }
    }
    return true;
}

void func(int x, int y, int w) {
    if (check(x, y, w)) {
        ans[board[x][y]]++;
        return;
    }

    int third = w / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func(x + third * i, y + third * j, third);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            board[i][j]++;
        }
    }

    func(0, 0, n);
    for (int i : ans) {
        cout << i << "\n";
    }
}