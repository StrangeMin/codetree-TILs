#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
int ret[100][100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    fill(&ret[0][0], &ret[0][0] + 100*100, 200000001);
    ret[0][n-1] = grid[0][n-1];


    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){

            int ny1 = j - 1;
            int nx1 = i;

            if(!(ny1 < 0 || ny1 >=n || nx1<0 || nx1 >=n)){
                ret[j][i] = min(ret[j][i], ret[ny1][nx1] + grid[j][i]);
            }

            int ny2 = j;
            int nx2 = i + 1; 

            if(!(ny2 < 0 || ny2 >=n || nx2<0 || nx2 >=n)){
                ret[j][i] = min(ret[j][i], ret[ny2][nx2] + grid[j][i]);
            }

        }
    }

    cout << ret[n-1][0] << "\n";
    // Write your code here!

    return 0;
}
