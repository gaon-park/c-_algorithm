#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> visited(100'001);

int main() {
	int n, k;
	cin >> n >> k;
	visited[n] = 1;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur * 2 < 100'001 && (visited[cur * 2] == 0 || visited[cur * 2] > visited[cur])) {
			q.push(cur * 2);
			visited[cur * 2] = visited[cur];
		}
		if (cur - 1 >= 0 && (visited[cur - 1] == 0 || visited[cur - 1] > visited[cur] + 1)) {
			q.push(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
		if (cur + 1 < 100'001 && (visited[cur + 1] == 0 || visited[cur + 1] > visited[cur] + 1)) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
	}

	cout << visited[k] - 1;

	return 0;
}