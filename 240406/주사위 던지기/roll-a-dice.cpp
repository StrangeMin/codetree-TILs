#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int n, m, r, c;
int dice[4][3];
int board[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
map<char, int> dir;

void toUp() {
	int tmp = dice[0][1];
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = dice[3][1];
	dice[3][1] = tmp;
}

void toDown() {
	int tmp = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = tmp;
}

void toRight() {
	int tmp = dice[0][1];
	dice[0][1] = dice[1][0];
	dice[1][0] = dice[2][1];
	dice[2][1] = dice[1][2];
	dice[1][2] = tmp;
}

void printDice() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
			cout << dice[i][j] << " ";
		cout << "\n";
	}
}

void toLeft() {
	int tmp = dice[0][1];
	dice[0][1] = dice[1][2];
	dice[1][2] = dice[2][1];
	dice[2][1] = dice[1][0];
	dice[1][0] = tmp;
}

void throwDice(char d) {

	int nx = c + dx[dir[d]];
	int ny = r + dy[dir[d]];

	if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		return;

	if (d == 'L')
		toLeft();
	else if (d == 'U')
		toUp();
	else if (d == 'R')
		toRight();
	else if (d == 'D')
		toDown();

	c = nx;
	r = ny;

	board[r][c] = dice[2][1];
}

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void initDice() {
	dice[0][1] = 1;
	dice[1][0] = 4;
	dice[1][1] = 2;
	dice[1][2] = 3;
	dice[2][1] = 6;
	dice[3][1] = 5;
}

int getSum() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (board[i][j])
				sum += board[i][j];
	}
	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r >> c;
	dir['L'] = 0;
	dir['U'] = 1;
	dir['R'] = 2;
	dir['D'] = 3;
	r--;
	c--;

	board[r][c] = 6;
	initDice();
	while (m--) {
		char d;
		cin >> d;
		throwDice(d);
	}
	cout << getSum() << "\n";
}