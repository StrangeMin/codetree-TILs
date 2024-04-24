#include <iostream>
#include <algorithm>

using namespace std;

int N, sy,sx, ret;
int board[5][5];
int direction[5][5];
int dx[8] = { 0,1,1,1,0,-1, - 1, - 1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

void go(int y, int x, int cnt) {
	int dir = direction[y][x];

	for(int i=1; i<N; i++){
		int ny = y + dy[dir] * i;
		int nx = x + dx[dir] * i;

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] < board[y][x])
			continue;

		go(ny, nx, cnt + 1);
	}

	ret = max(ret, cnt);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> direction[i][j];
			direction[i][j]--;
		}

	cin >> sy >> sx;
	sy--; sx--;

	go(sy, sx, 0);

	cout << ret << "\n";

	return 0;
}