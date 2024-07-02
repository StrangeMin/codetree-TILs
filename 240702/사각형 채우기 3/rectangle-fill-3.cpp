#include <iostream>

using namespace std;

int N;
long long dp[1001];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;

    for(int i=4; i<=N; i++){
        dp[i] = ((dp[i-1] * 3) + dp[i-2] - dp[i-3] )%1000000007;
    }

    cout << dp[N] << "\n";

    return 0;
}