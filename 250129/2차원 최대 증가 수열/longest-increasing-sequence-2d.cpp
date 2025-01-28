#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];
int ret =1;

void getJumpCnt(int y, int x){
    if(dp[y][x] == 0)
        return;

    for(int i=y+1; i<n; i++){
        for(int j=x+1; j<m; j++){
            if(grid[y][x] < grid[i][j])
                dp[i][j] = max(dp[i][j], dp[y][x] + 1);

            ret = max(ret, dp[i][j]);
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

    
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            getJumpCnt(i,j);
        }
    }

    //printArr();
    // Write your code here!
    cout << ret << "\n";

    return 0;
}
