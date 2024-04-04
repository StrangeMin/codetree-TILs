#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> location[401];
int board[21][21];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

pair<int, int> getSwapLocation(int y, int x) {
	int maxValue = -1;
	int ry, rx;

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (maxValue < board[ny][nx]) {
			maxValue = board[ny][nx];
			ry = ny;
			rx = nx;
		}
	}

	return { ry, rx };
}

void setNewLocation(int num, int y, int x) {
	location[num] = { y,x };
}

void swapNumber(int y1, int x1, int y2, int x2) {
	int tmp = board[y1][x1];
	board[y1][x1] = board[y2][x2];
	board[y2][x2] = tmp;

	setNewLocation(board[y1][x1], y1, x1);
	setNewLocation(board[y2][x2], y2, x2);
}

void printBoard() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			location[board[i][j]] = { i,j };
		}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	initBoard();

	while (M--) {

		for (int i = 1; i <= N * N; i++) {
			int y = location[i].first;
			int x = location[i].second;

			pair<int,int> point = getSwapLocation(y,x);
			swapNumber(y, x, point.first, point.second);
		}
	}

	printBoard();


	return 0;
}