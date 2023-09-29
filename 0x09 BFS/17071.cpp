#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int INF = 500'000;
int n, k; // n = 수빈이 위치, k = 동생의 위치
vector<int> dist(INF + 1);
vector<int> odd(INF + 1), even(INF + 1);
int d[] = { -1, 0, 1 };

void bfs(int st) {
	queue<pair<int, int>> Q;
	odd[st] = 1; // 짝수(0)초에 st에 방문 표시
	Q.push({ st, 1 });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 3; i++) {
			int next = (d[i] == 0 ? cur.first << 1 : cur.first + d[i]);
			if (next < 0 || next > INF) continue; // Out Of Bounds

			int a = cur.second + 1;
			if (cur.second & 1) { // 홀수이면 짝수로
				if (even[next] != 0 && even[next] <= a) continue; // 해당 위치에 이미 방문 했었음
				even[next] = a;
				Q.push({ next, a });
			}
			else { // 짝수이면 홀수로
				if (odd[next] != 0 && odd[next] <= a) continue;
				odd[next] = a;
				Q.push({ next, a });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int a = k;
	// 동생이 a위치에 언제 방문하는가?
	for (int i = 1; a <= INF; i++) {
		dist[a] = i;
		a += i;
	}
	// 수빈의 이동 가능한 모든 경로를 탐색
	bfs(n);

	int ans = INF + 1;
	// 1~INF 위치에 도착하는 시간
	for (int i = 1; i <= INF; i++) {
		if (dist[i] == 0) continue;
		if (odd[i] > 0 && odd[i] <= dist[i] && (dist[i] - odd[i]) % 2 == 0)
			ans = min(ans, dist[i]);
		if (even[i] > 0 && even[i] <= dist[i] && (dist[i] - even[i]) % 2 == 0)
			ans = min(ans, dist[i]);
	}

	if (ans == INF + 1) cout << -1;
	else cout << ans - 1;
}

/*
동생이 i위치에 방문할 수 있고
수빈이가 i위치에 동생보다 빠르거나 같게 도착했다면
i 위치에서 수빈이 +1 -1 하면서 기다리면 가장 빠르게 동생을 잡을 수 있는 경로가 된다!

이때 수빈이가 +1 -1 하는 시간은 고려할 필요가 없다
왜냐하면 ans는 어차피 동생의 시간으로 계산하기 때문이다!
*/
