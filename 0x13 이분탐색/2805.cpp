#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

// height 로 자를 때 총 나무 m만큼을 가져갈 수 있는가?
bool solve(long long height) {
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= height) continue;
		sum += (v[i] - height);
	}
	return sum >= m;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	long long st = 0, en = *max_element(v.begin(), v.end());
	while (st < en) {
		// st와 en이 1 차이날 때, st가 계속 값이 똑같이 유지될 수 있음
		long long mid = (st + en + 1) / 2; 
		if (solve(mid)) st = mid; // mid 이상 답이 될 수 있음
		else en = mid - 1; // mid 이상은 절대 답이 될 수 없음 
	}
	cout << st;
}
