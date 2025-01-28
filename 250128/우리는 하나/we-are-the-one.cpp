#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n, k, u, d;
int grid[8][8];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool visited[8][8];
vector<pair<int, int>> candidate;
int ret;

void combi(int start, vector<pair<int, int>> v) {
    if (v.size() == k) {

        fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < v.size(); i++) {
            cnt++;
            visited[v[i].first][v[i].second] = 1;
            q.push({ v[i].first, v[i].second });
        }

        while (q.size()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
                    continue;

                int diff = abs(grid[ny][nx] - grid[y][x]);

                if (u <= diff && diff <= d) {
                    q.push({ ny,nx });
                    cnt++;
                    visited[ny][nx] = 1;
                }
            }
        }
        ret = max(ret, cnt);
        return;
    }


    for (int i = start+1; i < candidate.size(); i++) {
        v.push_back(candidate[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            candidate.push_back({ i,j });
        }
    }

    vector<pair<int, int>> v;

    combi(-1, v);

    cout << ret << "\n";

    // Write your code here!

    return 0;
}

