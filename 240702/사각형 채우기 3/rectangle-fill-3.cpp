#include <iostream>

#define MAX_N 1000
#define MOD 1000000007

using namespace std;

int n;

long long dp[MAX_N + 1];

int main() {
    // 입력:
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;

    
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3) % MOD;
        for(int j = i - 3; j >= 0; j--)
            dp[i] = (dp[i] + dp[j] * 2) % MOD;
    }
    
    cout << dp[n];
    return 0;
}