#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<string> root;
vector<string> names;
unordered_map<string, unordered_set<string>> ancestors;
unordered_map<string, vector<string>> children;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		names.push_back(name);
		ancestors.insert({ name, {} });
		children.insert({ name, {} });
	}
	sort(names.begin(), names.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		string x, y;
		cin >> x >> y;
		ancestors[x].insert(y);
	}

	queue<string> q;
	for (auto it = ancestors.begin(); it != ancestors.end(); it++) {
		if (it->second.empty()) {
			q.push(it->first);
			root.push_back(it->first);
		}
	}
	sort(root.begin(), root.end());

	while (!q.empty()) {
		string name = q.front(); q.pop();
		for (auto it = ancestors.begin(); it != ancestors.end(); it++) {
			if (it->second.count(name)) {
				it->second.erase(name);

				if (it->second.empty()) { // 비었다면(자식이라면)
					q.push(it->first); // 다음 순서로 추가
					children[name].push_back(it->first); // 자식으로 추가
				}
			}
		}
	}

	cout << root.size() << "\n";
	for (string name : root) { // 가문의 시조들
		cout << name << " ";
	}
	cout << "\n";
	for (string name : names) { // 이름의 사전순
		cout << name << " " << children[name].size() << " ";
		sort(children[name].begin(), children[name].end());
		for (string child : children[name]) {
			cout << child << " ";
		}
		cout << "\n";
	}
}
