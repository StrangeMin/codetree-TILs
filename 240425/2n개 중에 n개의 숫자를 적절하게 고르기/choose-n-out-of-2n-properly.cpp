#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

#define MAX_N 10

using namespace std;

int n;
int num[2 * MAX_N];

int ans = INT_MAX;

void FindMin(int idx, int cnt, int diff) {
	if(idx == 2 * n) {
		if(cnt == n)
			ans = min(ans, abs(diff));
		return;
	}
    
    // 현재 숫자를 더하는 역할로 사용한 경우입니다.
	FindMin(idx + 1, cnt + 1, diff + num[idx]);
    // 현재 숫자를 더하는 빼는 역할로 사용한 경우입니다.
	FindMin(idx + 1, cnt, diff - num[idx]);
}

int main() {
	cin >> n;
	
	for(int i = 0; i < 2 * n; i++)
		cin >> num[i];
	
	FindMin(0, 0, 0);
	
	cout << ans;
	return 0;
}