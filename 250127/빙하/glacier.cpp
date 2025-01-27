#include <iostream>
#include <vector>

using namespace std;

int N, M;
int a[200][200];
int Next[200][200];
bool visited[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ret;
int Time;
vector<pair<int,int>> v;


bool dfs(int y, int x){

    visited[y][x] = true;
    v.push_back({y,x});

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >=N || nx < 0 || nx >= M){
            return true;
            break;
        }

        if(a[ny][nx] == 0 && !visited[ny][nx]){
            if(dfs(ny,nx))
                return true;
        }
            
    }

    return false;
}

void melting() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                v.clear();
                // 녹일 수 있는 물인지 판단
                fill(&visited[0][0], &visited[0][0] + 200*200, 0);
                if (!dfs(i,j)){
                    continue;
                }

                // 녹일 빙하 선택
                for (auto e : v) {
                    for(int k=0; k<4; k++){
                        int ny = e.first + dy[k];
                        int nx = e.second + dx[k];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                            continue;

                        if (Next[ny][nx] == 1) {
                            Next[ny][nx] = 0;
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    ret = cnt;
}

bool isDone() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Next[i][j] = a[i][j];
            }
        }

        // 시간 증가
        Time++;
        // 빙하 녹음
        melting();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = Next[i][j];
            }
        }

        // 다 녹았는지 체크
        if (isDone())
            break;
        
    }

    cout << Time << " " << ret << "\n";
    return 0;
}
