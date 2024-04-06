#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int N;
int board[101][101];
bool visited[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ret;
int dir;
int t;
int y, x;

// 1을 만났을 때

// 0 -> 3
// 1 -> 2
// 2 -> 1
// 3 -> 0

// 2를 만났을 때

// 0 -> 1
// 1 -> 0
// 2 -> 3
// 3 -> 2

void changeDirection() {

	if (board[y][x] == 1) {
		if (dir == 0) dir = 3;
		else if (dir == 1) dir = 2;
		else if (dir == 2) dir = 1;
		else if (dir == 3) dir = 0;
	}
	else if (board[y][x] == 2) {
		if (dir == 0) dir = 1;
		else if (dir == 1) dir = 0;
		else if (dir == 2) dir = 3;
		else if (dir == 3) dir = 2;
	}
}

int move() {
	t++;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		return -1;

	x = nx;
	y = ny;
	return 0;
}

void initYX(int ny, int nx) {
	y = ny;
	x = nx;
}

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	initBoard();

	//왼 -> 오
	for (int i = 0; i < N; i++) {
		dir = 2;
		initYX(i,0);
		t = 1;
		while (move() != -1) {
			changeDirection();
		}
		ret = max(ret, t);
	}

	// 위 -> 아
	for (int i = 0; i < N; i++) {
		dir = 3;
		initYX(0, i);
		t = 1;
		while (move() != -1) {
			changeDirection();
		}
		ret = max(ret, t);
	}

	// 오 -> 왼
	for (int i = 0; i < N; i++) {
		dir = 0;
		initYX(i,N-1);
		t = 1;
		while (move() != -1) {
			changeDirection();
		}
		ret = max(ret, t);
	}

	// 아 -> 위
	for (int i = 0; i < N; i++) {
		dir = 1;
		initYX(N-1, i);
		t = 1;
		while (move() != -1) {
			changeDirection();
		}
		ret = max(ret, t);
	}

	cout << ret << "\n";
}