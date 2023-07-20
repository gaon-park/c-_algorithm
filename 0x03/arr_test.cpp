#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N) {
    bool num[101]{};
    for (int i = 0; i < N; i++) {
        num[arr[i]] = true;
        if (num[100 - arr[i]]) return true;
    }
    return false;
}