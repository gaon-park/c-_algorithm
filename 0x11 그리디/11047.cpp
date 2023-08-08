#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	stack<int> S;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		S.push(tmp);
	}

	int cnt = 0;
	while (!S.empty()) {
		if (k / S.top() > 0) {
			cnt += k / S.top();
			k %= S.top();
		}
		S.pop();
	}
	cout << cnt;
}