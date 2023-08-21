#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int m, n;
vector<int> uni; // 우주
unordered_set<int> s; // 중복 제거한 행성 값
map<vector<int>, int> cnt; // 각 우주에서 행성들의 binary_search idx 결과들

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		uni.clear();
		s.clear();
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			uni.push_back(tmp);
			s.insert(tmp);
		}
		vector<int> sorted(s.begin(), s.end());
		sort(sorted.begin(), sorted.end());
		// 각 숫자가 정렬된 경우 몇 번째 idx 에 등장하는가?
		vector<int> idx;
		for (int j = 0; j < n; j++) {
			idx.push_back(lower_bound(sorted.begin(), sorted.end(), uni[j]) - sorted.begin());
		}
		// 같은 idx 배열을 갖는 것들끼리 모음
		cnt[idx]++;
	}

	int ans = 0;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second < 2) continue; // 짝을 이루려면 최소 2개는 있어야 함

		// 2개 이상인 경우, 각 우주들의 짝의 수 = 조합 갯수
		vector<int> brute(it->second, 1);
		fill(brute.begin(), brute.begin() + 2, 0);
		int cnt = 0;
		do {
			cnt++;
		} while (next_permutation(brute.begin(), brute.end()));
		ans += cnt;
	}
	cout << ans;
}
