#include <bits/stdc++.h>
#include <experimental/iterator>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    deque<int> que = {};
    vector<int> result = {};
    for (int i = 1; i <= n; i++) que.push_back(i);

    int cnt = 0;
    while (!que.empty()) {
        int num = que.front();
        que.pop_front();
        cnt++;

        if (cnt < k) {
            que.push_back(num);
        }
        else {
            cnt = 0;
            result.push_back(num);
        }
    }
    cout << '<';
    std::copy(result.begin(), result.end(),
        std::experimental::make_ostream_joiner(std::cout, ", "));
    cout << '>';

    return 0;
}