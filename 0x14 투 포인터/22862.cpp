#include <iostream>
#include <algorithm>

using namespace std;
int s[1'000'000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];

	int en = 0, cnt = 0; // cnt: 현재 보고 있는 연속 수열에서의 홀수 갯수
	if (s[en] % 2 == 1) cnt++;
	int max_len = 0;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && cnt + s[en + 1] % 2 <= k) {
			en++;
			cnt += s[en] % 2;
		}
		max_len = max(max_len, en - st + 1 - cnt);
		cnt -= s[st] % 2;
	}
	cout << max_len;
} 