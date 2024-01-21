#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, l;
int v[51];

bool solve(int x) {
	// 추가로 필요한 최소한의 휴게소 개수
	int must_cnt = 0;
	int pre = 0;
	for (int i = 0; i <= n; i++) {
		int dist = v[i] - pre;

		if (dist >= x) {
			if (dist % x != 0) 
				must_cnt += dist / x;
			else 
				must_cnt += (dist / x) - 1;
		}
		pre = v[i];
	}

	// 휴게소 개수가 m보다 크다면, 구간 최대값은 커져야함 (휴게소 수 감소)
	if (must_cnt > m) return true;
	// 휴게소 개수가 m보다 작거나 같다면, 구간 최대값은 커져도 됨 (휴게소 수 증가 가능)
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	sort(v, v + n);
	// (마지막 휴게소 ~ 도로 끝) 계산을 위해 l 삽입
	v[n] = l;

	int st = 1, en = l;
	while (st < en) {
		int mid = (st + en) / 2;
		if (solve(mid)) st = mid + 1;
		else en = mid;
	}
	cout << st;
}