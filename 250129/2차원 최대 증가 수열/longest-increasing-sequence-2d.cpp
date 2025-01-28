#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];
int ret;

void getJumpCnt(int y, int x){

    for(int i=0; i<=y-1; i++){
        for(int j=0; j<=x-1; j++){
            if(grid[y][x] > grid[i][j])
                dp[y][x] = max(dp[y][x], dp[i][j] + 1);

            ret = max(ret, dp[y][x]);
        }
    }
}

void printArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<m; i++)
        dp[0][i] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            getJumpCnt(i,j);
        }
    }

    //printArr();
    // Write your code here!
    cout << ret << "\n";

    return 0;
}
