#include <bits/stdc++.h>

using namespace std;

int n;
int card[500'000];

// 주어진 수가 들어갈 수 있는 가장 왼쪽 위치
int lower_idx(int target) {
	int st = 0, en = n;
	while (st < en) { // st = en 이 되면 가능한 구간이 한 곳이라는 의미
		int mid = (st + en) / 2;
		if (card[mid] < target) {
			st = mid + 1;
		} else if (card[mid] >= target) {
			en = mid;
		}
	}
	return st;
}

int upper_idx(int target) {
	int st = 0, en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (card[mid] > target) en = mid;
		else st = mid + 1;
	}
	return st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> card[i];
	sort(card, card + n);

	int m;
	cin >> m;
	while (m--) {
		int target;
		cin >> target;
		cout << upper_idx(target) - lower_idx(target) << " ";
	}
}