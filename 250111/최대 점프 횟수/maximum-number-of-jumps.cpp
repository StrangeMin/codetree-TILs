#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;

    for(int i=0; i<n; i++){

        for(int j=1; j<=arr[i]; j++){
            if(i+j >=n)
                continue;

            if(i>0 && dp[i] == 0)
                continue;

            dp[i+j] = max(dp[i]+1, dp[i+j]);
        }
    }

    int ret = 1;
    for(int i=0; i<n; i++)
        ret = max(ret, dp[i]);
        
    cout << ret << "\n";

    // Write your code here!

    return 0;
}