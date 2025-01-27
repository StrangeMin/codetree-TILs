#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[100][100];
int visited[100][100];
int r[10000], c[10000];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ret;
vector<pair<int,int>> candidate;

void combi(int start, vector<pair<int,int>> v, int y, int x){
    if(v.size() == m){

        // 돌 삭제
        for(auto e : v){
            grid[e.first][e.second] = 0;
        }

        int tmp = 1;
        
        fill(&visited[0][0], &visited[0][0] + 100*100, 0);
        queue<pair<int,int>> q;
        q.push({y,x});
        visited[y][x] = 1;

        while(q.size()){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int ny = curY + dy[i];
                int nx = curX + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || grid[ny][nx] == 1)
                    continue;

                visited[ny][nx] = visited[curY][curX] + 1;
                tmp++;
                q.push({ny,nx});
            }
        }

        ret = max(ret, tmp);


        // 돌 원복
        for(auto e : v){
            grid[e.first][e.second] = 1;
        }



        return;
    }

    for(int i=start+1; i<candidate.size(); i++){
        v.push_back(candidate[i]);
        combi(start, v, y, x);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 1){
                candidate.push_back({i,j});
            }
        };

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;

        vector<pair<int,int>> v;
        combi(-1, v, r[i], c[i]);
    }
    // Write your code here!

    cout << ret << "\n";

    return 0;
}
