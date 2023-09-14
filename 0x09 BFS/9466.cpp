#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];
int state[100005];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = VISITED;
		cur = arr[cur];
		// x가 사이클에 들어있거나, 들어있지 않은 정점을 방문
		if (state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN) {
			cur = x; // x에서 시작해서 지금까지 방문한 모든 정점을 NOT_CYCLE_IN 으로 바꿈
			while (state[cur] == VISITED) {
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}
		// x가 x가 아닌 정점에 재방문한 경우
		if (state[cur] == VISITED && cur != x) {
			int tmp = cur; // cur -> cur 까지 CYCLE_IN 으로 바꿈
			do {
				state[tmp] = CYCLE_IN;
				tmp = arr[tmp];
			} while (tmp != cur);
	
			tmp = x; // x -> cur 까지 NOT_CYCLE_IN 으로 바꿈
			while (tmp != cur) {
				state[tmp] = NOT_CYCLE_IN;
				tmp = arr[tmp];
			}
			return;
		}
		// x가 x로 돌아온 경우
		if (state[cur] == VISITED && cur == x) {
			int tmp = x; // x -> x 전부 CYCLE_IN 으로 바꿈
			do {
				state[tmp] = CYCLE_IN;
				tmp = arr[tmp];
			} while (tmp != x);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> arr[i];
		// 정점마다 방문하지 않았다면 사이클 체크
		for (int i = 1; i <= n; i++) 
			if (state[i] == NOT_VISITED) run(i);
		int cnt = 0;

		// 사이클에 해당하지 않는 정점 개수 세기
		for (int i = 1; i <= n; i++) 
			if (state[i] == NOT_CYCLE_IN) cnt++;
		cout << cnt << "\n";
	}
}