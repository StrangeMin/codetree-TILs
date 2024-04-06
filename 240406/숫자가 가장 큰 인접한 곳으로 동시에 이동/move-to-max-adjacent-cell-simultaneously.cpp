#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int N, M, T;
int board[21][21];
int cnt[21][21];
int nextCnt[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ret;
int dir;

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}

void setMarbleLocation() {
	int y, x;
	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		y--; x--;
		cnt[y][x] = 1;
	}
}

void move(int y, int x) {
	int tmp = -1;
	int ry, rx;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (board[ny][nx] > tmp) {
			ry = ny;
			rx = nx;
			tmp = board[ny][nx];
		}
	}
	nextCnt[ry][rx]++;
}

void copyCnt() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (nextCnt[i][j] == 0 || nextCnt[i][j] == 1)
				cnt[i][j] = nextCnt[i][j];
			else
				cnt[i][j] = 0;
		}
			
}

void getRestCnt() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (cnt[i][j])
				ret++;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	initBoard();
	setMarbleLocation();

	while (T--) {
		fill(&nextCnt[0][0], &nextCnt[0][0] + 21 * 21, 0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (cnt[i][j])
					move(i, j);
		copyCnt();
	}

	getRestCnt();
	cout << ret << "\n";
}