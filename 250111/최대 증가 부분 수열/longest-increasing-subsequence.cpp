#include <iostream>

using namespace std;

int N;
int M[1001];
int dp[1001];
int ret = 1;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> M[i];
    }

    //dp[N] : 길이가 N인 수열의 마지막 값을 나타냄.
    //수열의 길이가 1일 때 수열의 마지막 값을 M[1]으로 초기화
    dp[1] = M[1];

    for(int i=2; i<=N; i++){
        
        if(dp[ret] < M[i]){
            dp[++ret] = M[i];
        } else if(dp[ret] == M[i]){
            continue;
        } else {
            for(int j=ret; j>=1; j--){
                if(dp[j-1] < M[i]){
                    dp[j] = M[i];
                    break;
                }
            }
        }
    }

    // 1 2 5 6 4
    // 3 1 2
    /*
    dp[1] = 3
    
    */

    /*
    dp[1] = 1
    dp[2] = 2
    dp[3] = 5
    dp[4] = 6
    */

    cout << ret << "\n";
    // Write your code here!

    return 0;
}


// 수열의 마지막 값보다 큰 값이 나온 경우
// dp[최장 수열의 길이 + 1] = M[i]

// 수열의 마지막 값과 같은 값이 나온 경우
// continue;

// 수열의 마지막 값보다 작은 값이 나온 경우
// dp[해당 수열의 길이] = M[i]