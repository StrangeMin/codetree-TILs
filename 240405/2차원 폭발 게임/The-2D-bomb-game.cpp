#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int N, M, K;
int board[101][101];
bool visited[101][101];
int dx[2] = { 0,0 };
int dy[2] = {-1, 1 };
int tmp[101][101];

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}

bool isAvailable(int cnt) {
	return cnt >= M;
}

int getSameNumberAreaCnt(int y, int x) {
	int cur = board[y][x];
	int cnt = 1;
	visited[y][x] = true;

	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] || board[ny][nx] != cur)
			continue;

		cnt += getSameNumberAreaCnt(ny, nx);
	}
	return cnt;
}

void explosion(int y, int x) {
	int cur = board[y][x];
	board[y][x] = 0;
	visited[y][x] = true;

	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] || board[ny][nx] != cur)
			continue;

		explosion(ny, nx);
	}
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void rotate() {
	fill(&tmp[0][0], &tmp[0][0] + 101 * 101, 0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board[N - 1 - j][i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = tmp[i][j];
}

void gravity() {
	fill(&tmp[0][0], &tmp[0][0] + 101 * 101, 0);

	for (int i = 0; i < N; i++) {
		int curRow = N-1;
		for (int j = N-1; j >= 0; j--) {
			if (board[j][i] != 0) {
				tmp[curRow--][i] = board[j][i];
			}
		}
	}
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = tmp[i][j];
}

int getRestBombCnt() {
	int ret = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] != 0)
				ret++;
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	initBoard();

	while (K--) {
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && isAvailable(getSameNumberAreaCnt(i,j))) {
					fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
					explosion(i, j);
				}
			}
		gravity();
		rotate();
		gravity();

		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && isAvailable(getSameNumberAreaCnt(i, j))) {
				fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
				explosion(i, j);
			}
		}

	cout << getRestBombCnt() << "\n";

}