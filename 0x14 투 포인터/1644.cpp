#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> primes;

// 소수 배열 생성
void sieve() {
	vector<bool> state(n + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i)
			state[j] = false;
	}
	for (int i = 2; i <= n; i++) {
		if (state[i]) primes.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}

	sieve();

	int en = 0, sum = primes[0];
	int cnt = 0;
	for (int st = 0; st < primes.size(); st++) {
		while (en < primes.size() && sum < n) {
			en++;
			if (en < n) sum += primes[en];
		}
		if (sum == n) cnt++;
		sum -= primes[st];
	}
	cout << cnt;
}