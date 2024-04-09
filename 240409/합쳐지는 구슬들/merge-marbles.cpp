#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

int N, M, T;
pair<int, int> board[51][51];
vector<pair<int, int>> nextBoard[51][51];
char direction[2501];
map<char, int> directionCharToIndex;
map<int, char> dirctionIndexToChar;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int restCnt, heavyMarble;

bool isEmpty(int y, int x) {
	pair<int, int> empty = { 0,0 };
	return board[y][x] == empty;
}

void move(int y, int x) {
	int weight = board[y][x].first;
	int index = board[y][x].second;
	int dir = directionCharToIndex[direction[index]];

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
		dir = (dir + 2) % 4;
		direction[index] = dirctionIndexToChar[dir];
		nextBoard[y][x].push_back({ weight, index });
	}
	else {
		nextBoard[ny][nx].push_back({ weight, index });
	}
}

void combine(int y, int x) {
	int weightSum = nextBoard[y][x][0].first;
	int index = nextBoard[y][x][0].second;
	char dir = direction[index];

	for (int i = 1; i < nextBoard[y][x].size(); i++) {
		int curWeight = nextBoard[y][x][i].first;
		int curIndex = nextBoard[y][x][i].second;
		char curDir = direction[curIndex];

		weightSum += curWeight;

		if (curIndex > index) {
			index = curIndex;
			dir = curDir;
		}
	}

	nextBoard[y][x].clear();
	nextBoard[y][x].push_back({weightSum, index});
	direction[index] = dir;

}

void copyBoard() {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if (nextBoard[i][j].size()) {
				board[i][j] = nextBoard[i][j].back();
				nextBoard[i][j].clear();
			}
			else {
				board[i][j] = { 0,0 };
			}
}

void getResult() {
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			if (!isEmpty(i, j)) {
				restCnt++;
				heavyMarble = max(heavyMarble, board[i][j].first);
			}
		}
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j].first << " ";
		}
		cout << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	directionCharToIndex['L'] = 0;
	directionCharToIndex['U'] = 1;
	directionCharToIndex['R'] = 2;
	directionCharToIndex['D'] = 3;

	dirctionIndexToChar[0] = 'L';
	dirctionIndexToChar[1] = 'U';
	dirctionIndexToChar[2] = 'R';
	dirctionIndexToChar[3] = 'D';


	for (int i = 0; i < M; i++) {
		int r, c, w;
		char d;
		cin >> r >> c >> d >> w;
		board[--r][--c] = { w, i + 1 };
		direction[i + 1] = d;
	}

	while (T--) {
		
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if (!isEmpty(i,j)) {
					move(i,j);
				}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (nextBoard[i][j].size()) {
					combine(i, j);
				}

		copyBoard();
	}

	getResult();

	cout << restCnt << " " << heavyMarble << "\n";
}