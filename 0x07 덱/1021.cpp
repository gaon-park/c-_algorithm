#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    deque<int> que = {};
    int ans = 0;
    for (int i = 1; i <= n; i++) que.push_back(i);
    for (int i = 0; i < m; i++) {
        int index;
        cin >> index;
        // 앞에서부터 반 돌려봄
        int cnt = 0;
        while (cnt < que.size() / 2 && que.front() != index) {
            que.push_back(que.front());
            que.pop_front();
            cnt++;
        }
        if (que.front() == index) {
            ans += cnt;
        }
        // 못 찾았다면 다시 돌려놓고 뒤에서부터 찾아봄
        else {
            while (cnt > 0) {
                que.push_front(que.back());
                que.pop_back();
                cnt--;
            }
            while (que.front() != index) {
                que.push_front(que.back());
                que.pop_back();
                cnt++;
            }
            ans += cnt;
        }
        que.pop_front();
    }

    cout << ans;

    return 0;
}