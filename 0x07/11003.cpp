#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    deque<pair<int, int>> que = {};
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        // 오름차순 유지, 현재 입력된 값보다 더 큰 값이 있다면 필요 없으니까 pop
        while (!que.empty() && que.back().second > tmp) {
            que.pop_back();
        }
        // 현재 들어온 값은 항상 저장
        que.push_back({i, tmp});
        // 가장 최소값이 인덱스 범위를 벗어났다면 pop
        if (que.front().first <= i - l) que.pop_front();
        cout << que.front().second << ' ';
    }

    return 0;
}