#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

int N, M;
pair<int, int> position[401];
stack<int> board[21][21];
int maxNumberBoard[21][21];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void initBoard() {
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			board[i][j].push(num);
			position[num] = { i,j };
			maxNumberBoard[i][j] = num;
		}
}

pair<int, int> findNextPosition(int y, int x) {
	int tmp = 0;
	int ry=-1, rx=-1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || maxNumberBoard[ny][nx] == 0)
			continue;

		if (tmp < maxNumberBoard[ny][nx]) {
			tmp = maxNumberBoard[ny][nx];
			ry = ny;
			rx = nx;
		}
	}
	return { ry,rx };
}

void setMaxNumber(int y, int x) {
	maxNumberBoard[y][x] = 0;
	if (board[y][x].size() == 0) {
		return;
	}

	pair<int, int> pos = { y,x };
	for (int i = 1; i <= N * N; i++) {
		if (position[i] == pos) {
			maxNumberBoard[y][x] = max(maxNumberBoard[y][x], i);
		}
	}
}

void move(int targetNumber) {
	pair<int,int> curPosition = position[targetNumber];
	int y = curPosition.first;
	int x = curPosition.second;

	pair<int, int> nextPosition = findNextPosition(y, x);
	pair<int, int> emptyPosition = { -1,-1 };

	if (nextPosition == emptyPosition) {
		return;
	}

	stack<int> tmpStack;

	while (board[y][x].size() && board[y][x].top() != targetNumber) {
		int num = board[y][x].top();
		board[y][x].pop();
		tmpStack.push(num);
	}
	int num = board[y][x].top();
	board[y][x].pop();
	tmpStack.push(num);

	while (tmpStack.size()) {
		int num = tmpStack.top();
		tmpStack.pop();
		position[num] ={nextPosition.first, nextPosition.second};
		board[nextPosition.first][nextPosition.second].push(num);
	}

	setMaxNumber(y, x);
	setMaxNumber(nextPosition.first, nextPosition.second);

}

void printResult() {
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			if (!board[i][j].size()) {
				cout << "None" << "\n";
			}
			else {
				while (board[i][j].size()) {
					cout << board[i][j].top() << " ";
					board[i][j].pop();
				}
				cout << "\n";
			}
		}			
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].size())
				cout << board[i][j].top() << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

void printMaxNumber() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << maxNumberBoard[i][j] << " ";
		}
		cout << "\n";
	}
}

void printPosition() {
	for (int i = 1; i <= N*N; i++) {
		cout << i << ": " << position[i].first << "," << position[i].second << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	initBoard();
	while (M--) {
		int curNum;
		cin >> curNum;

		move(curNum);
	}

	printResult();
}