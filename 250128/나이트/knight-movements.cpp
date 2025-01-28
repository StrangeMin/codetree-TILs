#include <iostream>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
int dy[8] = {-1,-2,-2,-1, 1,2,2,1};
int dx[8] = {-2,-1, 1, 2, 2,1,-1,-2};
int visitied[100][100];

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int,int>> q;
    visitied[r1-1][c1-1] = 1;
    q.push({r1-1, c1-1});

    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >=n || nx < 0 || nx >= n || visitied[ny][nx])
                continue;

            visitied[ny][nx] = visitied[y][x] + 1;
            q.push({ny,nx});
        }

    }

    cout << visitied[r2-1][c2-1]-1 << "\n";
    // Write your code here!

    return 0;
}
