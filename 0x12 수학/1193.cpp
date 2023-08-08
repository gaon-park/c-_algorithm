#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	// x에서 1 2 3 ...을 빼다보면 찾는 수가 i 번째 군의 x번째 수가 된다
	int i = 1;
	while (x > i) {
		x -= i;
		i++;
	}

	int nume = x;
	int deno = i + 1 - x;
	if (i % 2) swap(nume, deno);
	cout << nume << "/" << deno;
}