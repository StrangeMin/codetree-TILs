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

void findFloodedArea(int y, int x, int k) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || board[ny][nx] > k)
			continue;

		findFloodedArea(ny, nx, k);
	}
}

void findSafeArea(int y, int x, int k) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
			continue;

		findSafeArea(ny, nx, k);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];


	for (int k = 1; k <= 100; k++) {
		fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && board[i][j] <= k)
					findFloodedArea(i, j, k);
			}

		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (!visited[i][j]) {
					findSafeArea(i, j, k);
					cnt++;
				}
			}

		if (cnt > ret) {
			ret = cnt;
			K = k;
		}
	}

	cout << K << " " << ret << "\n";
}