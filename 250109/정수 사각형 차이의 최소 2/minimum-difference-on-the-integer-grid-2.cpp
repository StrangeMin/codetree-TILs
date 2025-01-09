#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int grid[100][100];
pair<int,int> ret[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    ret[0][0] = {grid[0][0], grid[0][0]};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if(i==0 && j==0)
                continue;

            // 위
            int ny1 = i -1;
            int nx1 = j;
            int sum1 = 999999999;

            if(ny1 >= 0){
                sum1 = abs(max(grid[i][j], ret[ny1][nx1].second) -  min(grid[i][j], ret[ny1][nx1].first));
            }

            // 왼쪽    
            int ny2 = i;
            int nx2 = j-1;
            int sum2 = 999999999;

            if(nx2 >= 0){
                sum2 = abs(max(grid[i][j], ret[ny2][nx2].second) -  min(grid[i][j], ret[ny2][nx2].first));
            }

            if(sum1 < sum2){
                ret[i][j] = {min(grid[i][j], ret[ny1][nx1].first), max(grid[i][j], ret[ny1][nx1].second)};
            }
            else {
                ret[i][j] = {min(grid[i][j], ret[ny2][nx2].first), max(grid[i][j], ret[ny2][nx2].second)};
            }
        }
    }


    cout << ret[n-1][n-1].second - ret[n-1][n-1].first << "\n";
    

    // Write your code here!

    return 0;
}
