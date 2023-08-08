#include <bits/stdc++.h>

using namespace std;

int main() {
	string input;
	cin >> input;

	int sign = 1;
	int ans = 0;
	int tmp = 0;
	for (char c : input) {
		if (c == '+' || c == '-') {
			ans += tmp * sign;
			if (c == '-') sign = -1;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += c - '0';
		}
	}
	ans += tmp * sign;

	cout << ans;
}