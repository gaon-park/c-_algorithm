#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> M; // number, idx

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l;
	cin >> k >> l;

	int idx = 0;
	for (int i = 0; i < l; i++) {
		string stu;
		cin >> stu;
		M[stu] = idx++;
	}
	vector<pair<int, string>> v;
	for (auto it = M.begin(); it != M.end(); it++) {
		v.push_back({it->second, it->first}); // idx, number
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < min(k, int(v.size())); i++) {
		cout << v[i].second << "\n";
	}
}