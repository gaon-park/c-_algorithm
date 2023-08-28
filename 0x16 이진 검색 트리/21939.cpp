#include <bits/stdc++.h>

using namespace std;

int n, p, l;
int lev[100'002]; // 문제가 어떤 난이도인가?
set<int> pro[102]; // 난이도별 문제 저장

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> p >> l;
		lev[p] = l;
		pro[l].insert(p);
	}
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "recommend") {
			int x;
			cin >> x;
			if (x > 0) {
				for (int i = 100; i > 0; i--) {
					if (pro[i].empty()) continue; // 난이도별 문제가 비어있지 않은 곳까지 계속 가서
					cout << *prev(pro[i].end()) << "\n"; // 맨 마지막(문제번호가 큰) 것 출력
					break;
				}
			} else {
				for (int i = 1; i <= 100; i++) {
					if (pro[i].empty()) continue; // 난이도별 문제가 비어있지 않은 곳까지 계속 가서
					cout << *pro[i].begin() << "\n"; // 맨 처음(문제번호가 작은) 것 출력
					break;
				}
			}
		} else if (cmd == "add") {
			cin >> p >> l;
			lev[p] = l;
			pro[l].insert(p);
		} else { // solved
			cin >> p;
			pro[lev[p]].erase(p);
		}
	}
}