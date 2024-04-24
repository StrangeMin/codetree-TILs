#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int N, ret;
int arr[11];
int minCnt = INT_MAX;

void go(int here, int cnt) {
	if (here == N-1) {
		minCnt= min(minCnt, cnt);
		return;
	}

	for (int i = 1; i <= arr[here]; i++) {
		go(here + i, cnt + 1);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	go(0,0);

	ret = (minCnt == INT_MAX ? -1 : minCnt);

	cout << ret << "\n";

	return 0;
}