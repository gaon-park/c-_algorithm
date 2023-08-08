#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> state;

int main() {
	int n, k;
	cin >> n >> k;
	state.assign(n + 1, true);
	state[1] = false;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (!state[j]) continue;
			state[j] = false;
			cnt++;
			if (cnt == k) {
				cout << j;
				return 0;
			}
		}
	}
}