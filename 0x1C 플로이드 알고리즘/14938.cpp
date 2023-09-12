#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 0x3f3f3f3f;
using namespace std;

int n, m, r;
int item[105];
int isused[105];

int dist[105][105];
int nxt[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
		fill(dist[i], dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = min(dist[a][b], l);
		dist[b][a] = min(dist[b][a], l);
		nxt[a][b] = b;
		nxt[b][a] = a;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j], dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	int ans = 0, tmp;
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		fill(isused, isused + n + 1, 0);
		
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] > m) continue;
			
			int st = i;
			while (st != j) {
				isused[st] = 1;
				st = nxt[st][j];
			}
			isused[j] = 1;
		}

		for (int j = 1; j <= n; j++) {
			if (isused[j]) tmp += item[j];
		}
		ans = max(ans, tmp);
	}

	cout << ans;
}
