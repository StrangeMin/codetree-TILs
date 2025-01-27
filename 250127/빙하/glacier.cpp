#include <iostream>

using namespace std;

int N, M;
int a[200][200];
int Next[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ret;

void melting() {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                // 녹일 수 있는 물인지 판단
                int iceCnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx]) {
                        iceCnt++;
                        continue;
                    }
                }

                if (iceCnt == 4)
                    continue;

                // 녹일 빙하 선택
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

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
    int time = 0;

    while (true) {

        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Next[i][j] = a[i][j];
            }
        }

        // 시간 증가
        time++;
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

    cout << time << " " << ret << "\n";
    return 0;
}
