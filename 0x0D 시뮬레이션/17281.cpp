#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int vec[55][10]; // 각 이닝의 결과
int order[9];

int simulation() {
    int turn = 0;
    int out = 0;
    int idx = 0; // 현재 순서
    int score = 0;
    int base[3] = {};
    while (turn < N) {
        int cur_result = vec[turn][order[idx]];
        if (cur_result == 0) {
            out++;
            if (out == 3) {
                turn++;
                out = 0;
                fill(base, base + 3, 0);
            }
        }
        else if (cur_result == 1) {
            score += base[2];
            base[2] = base[1];
            base[1] = base[0];
            base[0] = 1;
        }
        else if (cur_result == 2) {
            score += base[2];
            score += base[1];

            base[2] = base[0];
            base[1] = 1;
            base[0] = 0;
        }
        else { // 3 or 4
            for (int i = 0; i < 3; i++) {
                score += base[i];
                base[i] = 0;
            }
            if (cur_result == 3) base[2] = 1;
            else score++;
        }
        ++idx;
        if (idx >= 9) idx = 0;
    }

    return score;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> vec[i][j];
        }
    }

    vector<int> brute(8);
    for (int i = 0; i < 8; ++i) {
        brute[i] = i + 1;
    }
    order[3] = 0;

    int score = 0;
    do {
        copy(brute.begin(), brute.begin() + 3, order);
        copy(brute.begin() + 3, brute.end(), order + 4);
        score = max(score, simulation());
    } while (next_permutation(brute.begin(), brute.end()));

    cout << score;
}
