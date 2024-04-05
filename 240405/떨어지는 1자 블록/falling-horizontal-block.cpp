#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int N, M, K;
int board[101][101];

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}


void setBlock(int sy, int sx) {
	while (M--) {
		board[sy][sx] = 1;
		sx++;
	}
}

void dropBlock() {
	bool isDone = false;
	for (int i = 0; i < N; i++) {
		for (int j = K - 1; j < K + M - 1; j++) {
			if (board[i][j]) {
				isDone = true;
				setBlock(i-1, K-1);
				return;
			}
		}
	}

	if (!isDone) {
		setBlock(N-1, K-1);
	}
}

void printBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M >> K;

	initBoard();
	dropBlock();
	printBoard();

}