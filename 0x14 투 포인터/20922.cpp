#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;
int arr[200'000];
unordered_map<int, int> cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int en = 0, ans = 0;
	cnt[arr[0]] = 1;
	for (int st = 0; st < n; st++) {
		while (en < n - 1) {
			if (cnt[arr[en + 1]] + 1 > k) break;
			
			en++;
			cnt[arr[en]]++;
		}
		ans = max(ans, en - st + 1);
		cnt[arr[st]]--;
	}
	cout << ans;
} 