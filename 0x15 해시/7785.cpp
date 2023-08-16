#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	unordered_set<string> enter;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "leave") enter.erase(name);
		else enter.insert(name);
	}
	vector<string> ans(enter.begin(), enter.end());
	sort(ans.rbegin(), ans.rend());
	for (string s : ans) cout << s << "\n";
} 