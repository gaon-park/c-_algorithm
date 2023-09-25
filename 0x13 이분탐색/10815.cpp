#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> cards;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cards.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	vector<int> vec(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> vec[i];
	}

	for (int num : vec) {
		int st = 0, en = n - 1;
		while (st < en) {
			int mid = (st + en) / 2;
			if (cards[mid] < num) {
				st = mid + 1;
			}
			else
				en = mid;
		}
		if (cards[st] == num) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}
