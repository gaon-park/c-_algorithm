#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<int> line(100005, -1); // prev

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	queue<pair<int, int>> Q;
	line[n] = n;
	Q.push({n, 0});
	int toK = -1;
	while (!Q.empty()) {
		int cur = Q.front().first;
		int dist = Q.front().second;
		Q.pop();
		if (cur == k) {
			toK = dist;
			break;
		}
		if (cur - 1 >= 0 && line[cur - 1] == -1) {
			line[cur - 1] = cur;
			Q.push({cur - 1, dist + 1});
		} 
		if (cur + 1 <= 100000 && line[cur + 1] == -1) {
			line[cur + 1] = cur;
			Q.push({cur + 1, dist + 1});
		}
		if (cur * 2 <= 100000 && line[cur * 2] == -1) {
			line[cur * 2] = cur;
			Q.push({cur * 2, dist + 1});
		}
	}
	
	cout << toK << "\n";
	vector<int> path;
	while (k != n) {
		path.push_back(k);
		k = line[k];
	}
	path.push_back(n);
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}
