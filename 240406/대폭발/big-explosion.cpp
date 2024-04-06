#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int N, M, r, c;
int board[101][101];
int tmp[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int t;

void bomb(int y, int x) {
	int weight = pow(2, t - 1);
	tmp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * weight;
		int nx = x + dx[i] * weight;

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		tmp[ny][nx] = 1;
	}
}

void makeCopy() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = tmp[i][j];
}

int getBombCnt() {
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j])
				cnt++;

	return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> r >> c;
	r--;
	c--;

	board[r][c] = 1;

	while (M--) {
		t++;
		fill(&tmp[0][0], &tmp[0][0] + 101 * 101, 0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (board[i][j])
					bomb(i, j);
		makeCopy();
	}

	cout << getBombCnt() << "\n";
}