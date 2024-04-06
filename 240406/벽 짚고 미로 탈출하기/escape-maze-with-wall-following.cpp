#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int N, dir,y,x;
char board[101][101];
int visited[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool done;
bool cantEscape = false;
int ret;

void turnLeft() {
	dir = (dir + 3) % 4;
}

void turnRight() {
	dir = (dir + 1) % 4;
}

bool checkWallOnRight() {
	int ry = y + dy[dir] + dy[(dir + 1) % 4];
	int rx = x + dx[dir] + dx[(dir + 1) % 4];

	if (ry < 0 || ry >= N || rx < 0 || rx >= N)
		return false;

	if (board[ry][rx] == '#')
		return true;

	return false;
}

bool canEscape() {
	int ry = y + dy[dir];
	int rx = x + dx[dir];

	if (ry < 0 || ry >= N || rx < 0 || rx >= N)
		return true;

	return false;
}

bool canMove() {
	int ry = y + dy[dir];
	int rx = x + dx[dir];

	if (board[ry][rx] == '#')
		return false;

	return true;
}

void move() {
	y = y + dy[dir];
	x = x + dx[dir];
	visited[y][x]++;
	ret++;

	if (visited[y][x] >= 2)
		cantEscape = true;
}

void decideBehavior() {
	if (canEscape()) {
		done = true;
		ret++;
		return;
	}
	else if (canMove()) {
		// 오른쪽에 벽이 있는 경우
		if (checkWallOnRight()) {
			move();
		}
		// 벽이 없는 경우
		else {
			move();
			turnRight();
			move();
		}
	}
	else {
		turnLeft();
	}
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

	cin >> N >> y >> x;
	y--;
	x--;

	visited[y][x]++;
	dir = 2;
	initBoard();

	while (done == false && cantEscape == false) {
		decideBehavior();
	}

	if (cantEscape == true)
		ret = -1;

	cout << ret << "\n";
}