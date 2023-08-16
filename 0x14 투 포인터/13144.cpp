#include <iostream>
#include <algorithm>

using namespace std;
int arr[100'000];
int isused[100'001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int en = 0; 
	long long cnt = 0;
	isused[arr[0]] = 1;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && isused[arr[en + 1]] == 0) {
			en++;
			isused[arr[en]] = 1;
		}
		cnt += (en - st + 1);
		isused[arr[st]] = 0;
	}
	cout << cnt;
} 