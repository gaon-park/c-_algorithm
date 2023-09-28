#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int board[500005];
int isused[2][500005]; // 짝수, 홀수 초에 도착했을 경우

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}

	queue<int> Q;
	Q.push(n);
	isused[0][n] = 1;

	int t = 1; // time
	bool meet = false;

	while (!Q.empty()) {
		k += t; // 현재 동생의 위치
		if (k > 500000) break; // 범위 초과
		if (isused[t & 1][k]) { // 만났다!
			meet = true;
			break;
		}
		// 현재 수빈의 위치에서 움직일 수 있는 곳을 탐색
		int qsize = Q.size();
		for (int i = 0; i < qsize; i++) {
			int from = Q.front(); Q.pop();
			for (int to : {from * 2, from + 1, from - 1}) {
				// 범위 밖이거나, 수빈이 to 위치에 방문한 적이 있는 경우
				if (to < 0 || to > 500000 || isused[t & 1][to]) continue;
				// 바로 만난 경우
				if (to == k) {
					meet = true;
					break;
				}
				isused[t & 1][to] = isused[(t + 1) & 1][from] + 1;
				Q.push(to);
			}
			if (meet) break;
		}
		if (meet) break;
		t++;
	}
	meet ? cout << t : cout << -1;
}
