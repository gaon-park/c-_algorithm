#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tk; // 원래 진실을 알고 있던 사람
int parent[55];
vector<int> party[55]; // 파티에 참가하는 사람 리스트

int find_parent(int a) {
	if (a == -1 || parent[a] == -1) return -1;
	if (a == parent[a]) return a;
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int truthCnt;
	cin >> truthCnt;
	while (truthCnt--) {
		int tmp;
		cin >> tmp;
		tk.push_back(tmp);
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i : tk) {
		parent[i] = -1;
	}
	
	for (int party_idx = 1; party_idx <= m; party_idx++) {
		int cnt;
		cin >> cnt;
		int pre = 0;
		for (int i = 0; i < cnt; i++) {
			int person;
			cin >> person;
			party[party_idx].push_back(person);
			if (pre == 0) {
				pre = person;
				continue;
			}
			union_parent(pre, person);
			pre = person;
		}
	}

	int cnt = 0;
	for (int party_idx = 1; party_idx <= m; party_idx++) {
		vector<int> p = party[party_idx];
		bool res = true;
		for (int person : p) { // 파티에 참가하는 사람
			if (find_parent(person) == -1) {
				res = false;
				break;
			}
		}
		if (res) cnt++;
	}

	cout << cnt;
}