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
char nextCnt[51][51];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0,-1,0,1 };
map<char, int> dir;

void initBoard() {
	fill(&board[0][0], &board[0][0] + 51 * 51, '0');
	fill(&nextCnt[0][0], &nextCnt[0][0] + 51 * 51, '0');

	for (int i = 0; i < M; i++) {
		int y, x;
		char d;
		cin >> y >> x >> d;
		board[--y][--x] = d;
	}
}

void copyBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = nextCnt[i][j];

	fill(&nextCnt[0][0], &nextCnt[0][0] + 51 * 51, '0');
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
	char point = nextCnt[y][x];
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
		// 이미 구슬이 있으면 
		// 구슬 삭제
		// return
		if (isThereMarble(y, x)) {
			nextCnt[y][x] = '0';
			return;
		}

		// 구슬 없으면 방향 반대로 바꿈
		// return
		char newDir = idxToChar((curDir + 2) % 4);
		nextCnt[y][x] = newDir;
		return;
	}

	// ny,nx로 이동
	// 이동한 위치에 구슬 있으면
	// 구슬 삭제
	if (isThereMarble(ny, nx)) {
		nextCnt[ny][nx] = '0';
		return;
	}
	nextCnt[ny][nx] = idxToChar(curDir);
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