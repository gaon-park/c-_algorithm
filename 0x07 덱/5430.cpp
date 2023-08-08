#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string ans = "";
    while (t > 0) {
        t--;
        string s, arr;
        int n;
        cin >> s >> n >> arr;
        arr.erase(remove(arr.begin(), arr.end(), '['));
        arr.erase(remove(arr.begin(), arr.end(), ']'));
        // , 구분자 넣어서 큐에 넣어줌
        string tmp = "";
        deque<int> que = {};
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == ',') {
                que.push_back(stoi(tmp));
                tmp = "";
            }
            else {
                tmp += arr[i];
            }
        }
        if (tmp.size() > 0) que.push_back(stoi(tmp));

        int direction = 1; // 양수인 경우 앞, 음수인 경우 뒤
        bool flg = true;
        for (char c : s) {
            if (c == 'R') {
                direction *= -1;
            }
            // D
            else {
                if (que.empty()) {
                    flg = false;
                    break;
                }
                if (direction > 0) {
                    que.pop_front();
                }
                else {
                    que.pop_back();
                }
            }
        }
        if (flg) {
            ans += "[";
            if (direction > 0) {
                for (auto it = que.begin(); it != que.end(); it++) {
                    ans += to_string(*it);
                    if (it + 1 != que.end()) ans += ",";
                }
            }
            else {
                for (auto it = que.rbegin(); it != que.rend(); it++) {
                    ans += to_string(*it);
                    if (it + 1 != que.rend()) ans += ",";
                }
            }
            ans += "]\n";
        }
        else ans += "error\n";
    }
    cout << ans;

    return 0;
}