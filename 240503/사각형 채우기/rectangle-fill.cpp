#include <iostream>

using namespace std;

int dp[1001];
int ret;

int go(int n){
    if(dp[n])
        return dp[n];

    dp[n] = (go(n-1) + go(n-2)) % 10007;

    return dp[n];
}
int main() {
    
    dp[1]= 1;
    dp[2] = 2;
    dp[3] = 3;

    int N;
    cin >> N;

    ret = go(N);

    cout << ret << "\n";

    return 0;
}