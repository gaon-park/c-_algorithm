#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100'001];
int dist[100'001];

int main() {
    cin >> n >> k;
    queue<int> Q;
    Q.push(n);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (cur == k) break;

        if (cur + 1 < 100'001 && dist[cur + 1] == 0) {
            Q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
        } 
        if (cur - 1 >= 0 && dist[cur - 1] == 0) {
            Q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
        }
        if (cur * 2 < 100'001 && dist[cur * 2] == 0) {
            Q.push(cur * 2);
            dist[cur * 2] = dist[cur] + 1;
        }
    }
    cout << dist[k];

    return 0;
}