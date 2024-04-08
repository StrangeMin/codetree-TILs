#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int N, M, T;
char board[51][51];
char nextDir[51][51];
int nextCnt[51][51];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0,-1,0,1 };
map<char, int> dir;

void initBoard() {
	fill(&board[0][0], &board[0][0] + 51 * 51, '0');
	fill(&nextDir[0][0], &nextDir[0][0] + 51 * 51, '0');

	for (int i = 0; i < M; i++) {
		int y, x;
		char d;
		cin >> y >> x >> d;
		board[--y][--x] = d;
	}
}

void copyBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (nextCnt[i][j] <= 1)
				board[i][j] = nextDir[i][j];
			else
				board[i][j] = '0';
		}
	fill(&nextCnt[0][0], &nextCnt[0][0] + 51 * 51, 0);
	fill(&nextDir[0][0], &nextDir[0][0] + 51 * 51, '0');
}

char idxToChar(int idx) {
	if (idx == 0)
		return 'L';
	else if (idx == 1)
		return 'U';
	else if (idx == 2)
		return 'R';
	else if (idx == 3)
		return 'D';
}

bool isThereMarble(int y, int x) {
	char point = nextDir[y][x];
	return point == 'L' || point == 'U' || point == 'R' || point == 'D';
}

bool isThereMarbleInBoard(int y, int x) {
	char point = board[y][x];
	return point == 'L' || point == 'U' || point == 'R' || point == 'D';
}

void move(int y, int x) {
	int curDir = dir[board[y][x]];

	int ny = y + dy[curDir];
	int nx = x + dx[curDir];

	if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
		char newDir = idxToChar((curDir + 2) % 4);
		nextDir[y][x] = newDir;
		nextCnt[y][x]++;
		return;
	}

	// ny,nx로 이동
	// 이동한 위치에 구슬 있으면
	// 구슬 삭제
	nextDir[ny][nx] = idxToChar(curDir);
	nextCnt[ny][nx]++;
}

int getMarbleCnt() {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (isThereMarbleInBoard(i, j))
				ret++;
	return ret;
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	dir['L'] = 0;
	dir['U'] = 1;
	dir['R'] = 2;
	dir['D'] = 3;

	while (T--) {
		cin >> N >> M;
		initBoard();
		for (int k = 0; k < 2 * N; k++) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (isThereMarbleInBoard(i, j)) {
						move(i, j);
					}
			copyBoard();
		}
		cout << getMarbleCnt() << "\n";
	}
}