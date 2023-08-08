#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	stack<int> stack = {};
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n == 0) stack.pop();
		else stack.push(n);
	}
	int sum = 0;
	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}
	cout << sum;

	return 0;
}