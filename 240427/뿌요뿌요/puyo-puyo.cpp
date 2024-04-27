#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
bool row[11];
bool column[11];
int board[51][51];
bool visited[51][51];
int ret = INT_MIN;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int y, int x, int k) {
	visited[y][x] = true;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || board[ny][nx] != k)
			continue;

		cnt += dfs(ny, nx, k);
	}

	return cnt + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N ;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int blockSize = dfs(i, j, board[i][j]);

				if (blockSize >= 4) {
					K++;
				}
				ret = max(ret, blockSize);
			}
		}

	cout << K << " " << ret << "\n";
}