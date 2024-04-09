#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <stack>
using namespace std;


vector<pair<int,int>> board[51][51];
vector<pair<int,int>> nextBoard[51][51];
char direction[2501];
int N, M, T, K;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

void addMarble(int index) {
	int r, c;
	char dir;
	int velocity;
	cin >> r >> c >> dir >> velocity;
	board[--r][--c].push_back({velocity, index});
	direction[index] = dir;
}

int directionCharToIndex(char dir) {
	if (dir == 'L')
		return 0;
	else if (dir == 'U')
		return 1;
	else if (dir == 'R')
		return 2;
	else if (dir == 'D')
		return 3;
}

char directionIndexToChar(int dir) {
	if (dir == 0)
		return 'L';
	else if (dir == 1)
		return 'U';
	else if (dir == 2)
		return 'R';
	else if (dir == 3)
		return 'D';
}

bool isAvailableRange(int coordinate) {
	return 0 <= coordinate && coordinate < N;
}

void getNextPosition(int& position) {
	if (position < 0)
		position = -position;
	else if (position >= N) {
		int excessDistance = (position - (N - 1));
		position = position - (excessDistance * 2);
	}
}

pair<int, int> getNextPosition(int y, int x, int velocity, int& dir) {
	int rest = velocity % (2 * N -2);

	y = y + dy[dir] * rest;
	x = x + dx[dir] * rest;

	while (!(isAvailableRange(y) && isAvailableRange(x)) ) {
		getNextPosition(y);
		getNextPosition(x);
		dir = (dir + 2) % 4;
	}
	return { y,x };
}

void move(int y, int x) {
	pair<int,int> marble = board[y][x].back();
	int velocity = marble.first;
	int index = marble.second;
	int dir = directionCharToIndex(direction[index]);
	board[y][x].pop_back();

	pair<int, int> nextPosition = getNextPosition(y, x, velocity, dir);
	nextBoard[nextPosition.first][nextPosition.second].push_back({velocity,index});
	//dir 세팅
	direction[index] = directionIndexToChar(dir);
}


void printNextPosition() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (nextBoard[i][j].size())
				cout << nextBoard[i][j].back().second << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

bool isOverCnt(int cnt) {
	return cnt > K;
}

void eraseExceedMarble(int y, int x) {
	sort(nextBoard[y][x].begin(), nextBoard[y][x].end(), cmp);

	while (isOverCnt(nextBoard[y][x].size())) {
		nextBoard[y][x].pop_back();
	}
}

void copyBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			board[i][j] = nextBoard[i][j];
			nextBoard[i][j].clear();
		}
}

int getRestMarbleCnt() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cnt += board[i][j].size();
	return cnt;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T >> K;

	for (int i = 0; i < M; i++) {
		addMarble(i + 1);
	}

	while (T--) {
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				while(board[i][j].size()) {
					move(i, j);
				}
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				int size = nextBoard[i][j].size();
				if(isOverCnt(size)) {
					eraseExceedMarble(i, j);
				}
			}
		copyBoard();
	}

	cout << getRestMarbleCnt() << "\n";
}