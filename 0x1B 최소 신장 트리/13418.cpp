#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int cost;
	int a, b;

	bool operator<(Edge& edge) const {
		return cost < edge.cost;
	}
};

int n, m;
vector<Edge> vec;
int parent_bad[1010];
int parent_good[1010];

int find_parent(int a, int parent[1010]) {
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a], parent);
}

bool union_parent(int a, int b, int parent[1010]) {
	a = find_parent(a, parent);
	b = find_parent(b, parent);
	if (a == b) return false;
	parent[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent_bad[i] = i;
		parent_good[i] = i;
	}
	for (int i = 0; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c == 1 ? 0 : 1, a, b });
	}
	sort(vec.begin(), vec.end());
	// 최악의 케이스
	int bad = 0;
	for (auto it = vec.rbegin(); it != vec.rend(); it++) {
		if (union_parent(it->a, it->b, parent_bad)) {
			bad += it->cost;
		}
	}
	bad *= bad;
	// 최선의 케이스
	int good = 0;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (union_parent(it->a, it->b, parent_good)) {
			good += it->cost;
		}
	}
	good *= good;

	cout << bad - good;
}
