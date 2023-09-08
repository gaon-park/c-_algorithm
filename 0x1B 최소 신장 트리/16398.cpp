#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	long long cost;
	int a, b;

	bool operator<(Edge e) const {
		return cost < e.cost;
	}
};

int v, e;
vector<Edge> vec;
int parent[1010]; // union find 

int find_parent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else if (b < a) {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v;
	for (int i = 1; i <= v; i++) { // 정점은 1번~V번
		parent[i] = i; // 자기 자신을 부모로 초기화
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			int cost;
			cin >> cost;
			if (cost > 0) {
				vec.push_back({ cost, i, j });
			}
		}
	}
	sort(vec.begin(), vec.end()); // cost 오름차순
	long long ans = 0;
	for (auto& edge : vec) {
		if (find_parent(edge.a) == find_parent(edge.b)) continue;
		union_parent(edge.a, edge.b);
		ans += edge.cost;
	}

	cout << ans;
}
