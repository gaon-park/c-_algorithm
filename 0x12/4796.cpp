#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int idx = 1;
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c && a == 0) break;
		int tmp1 = c % b;
		int tmp2 = c / b;
		cout << "Case " << idx++ << ": " << tmp2 * a + (tmp1 > 0 ? min(tmp1, a) : 0) << "\n";
	}
}