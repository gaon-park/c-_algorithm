#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b;
    long long cost;
    bool operator < (Edge e) const {
        return cost < e.cost;
    }
};

int n, m;
vector<Edge> vec;
vector<int> parent;

int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) parent.push_back(i);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({ a, b, c });
    }
    sort(vec.begin(), vec.end());
    
    long long ans = 0;
    long long _max = 0;
    for (auto cur : vec) {
        if (find_parent(cur.a) == find_parent(cur.b)) continue;
        union_parent(cur.a, cur.b);
        ans += cur.cost;
        _max = max(cur.cost, _max);
    }
    cout << ans - _max;
}
