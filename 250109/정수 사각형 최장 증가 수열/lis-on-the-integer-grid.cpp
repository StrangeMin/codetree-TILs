#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[500][500];
int visited[500][500];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ret;

int go(int y, int x){

    visited[y][x] = 1;

    int cnt = 1;
    int tmp = 0;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n || grid[ny][nx] >= grid[y][x])
            continue;

        if(visited[ny][nx]){
            tmp = max(tmp, visited[ny][nx]);
        }
        else{
            tmp = max(tmp, go(ny,nx));
        }
    }

    visited[y][x] = cnt + tmp;
    return visited[y][x];
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j])
                go(i,j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, visited[i][j]);
        }
    }

    cout << ret << "\n";

    // Write your code here!

    return 0;
}
