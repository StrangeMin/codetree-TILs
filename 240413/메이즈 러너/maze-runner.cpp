#include <iostream>
#include <cmath>
using namespace std;

int N, M, K;
int exitY, exitX;
int board[11][11];
bool isEscaped[11];
int moveDistance[11];
pair<int, int> playerLocation[11];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int playerBoard[11][11];

int getDistanceFromExit(int y, int x) {
	return abs(y - exitY) + abs(x - exitX);
}

void moveAll() {
	for (int i = 1; i <= M; i++) {
		if (isEscaped[i] == true)
			continue;

		int y = playerLocation[i].first;
		int x = playerLocation[i].second;
		int curDistance = getDistanceFromExit(y, x);

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			int nextDistance = getDistanceFromExit(ny, nx);

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[ny][nx] > 0)
				continue;

			if (nextDistance < curDistance) {
				curDistance = nextDistance;
				playerLocation[i] = { ny,nx };
			}
		}

		if (y != playerLocation[i].first || x != playerLocation[i].second)
			moveDistance[i]++;

		if (playerLocation[i].first == exitY && playerLocation[i].second == exitX) {
			isEscaped[i] = true;
		}
	}
}

bool isIncludePlayer(int y, int x) {
	for (int i = 1; i <= M; i++)
		if (isEscaped[i] == false && playerLocation[i].first == y && playerLocation[i].second == x)
			return true;

	return false;
}

bool checkCondition(int y, int x, int squareSize) {
	if (y + squareSize > N || x + squareSize > N)
		return false;
	bool IncludePlayer = false;
	bool IncludeExit = false;

	for (int i = y; i < y + squareSize; i++) {
		for (int j = x; j < x + squareSize; j++) {
			if (isIncludePlayer(i, j))
				IncludePlayer = true;

			if (i == exitY && j == exitX)
				IncludeExit = true;


		}
	}
	if (IncludeExit && IncludePlayer)
		return true;

	return false;
}

/*
 {0,0} {0,1} {0,2}

 {1,0} {1,1} {1,2}

 {2,0} {2,1} {2,2}


 {2,0} {1,0} {0,0}

 {2,1} {1,1} {0,1}

 {2,2} {1,2} {0,2}

 {1,2} <- {0,1}
 
 {0,1} <- {1,1}

 {j, N-1 - i} <- {i,j}
 {2,1} <- {1,2}
 {} <- {y,x}
 {1,1}<-{1,0}
*/

void rotatePlayer(int y, int x, int squareSize) {
	for (int i = 1; i <= M; i++) {
		if (!isEscaped[i]) {
			int playerY = playerLocation[i].first;
			int playerX = playerLocation[i].second;

			if (y <= playerY && playerY < y + squareSize && x <= playerX && playerX < x + squareSize) {

				int oy = playerY - y;
				int ox = playerX - x;

				int nx = squareSize - 1 - oy;
				int ny = ox;


				playerLocation[i] = { ny + y,nx + x };
			}
		}
	}
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void printPlayerLocation() {
	fill(&playerBoard[0][0], &playerBoard[0][0] + 11 * 11, 0);
	for (int i = 1; i <= M; i++) {
		if (!isEscaped[i])
			playerBoard[playerLocation[i].first][playerLocation[i].second] = i;
	}

	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << playerBoard[i][j] << " ";
		cout << "\n";
	}

}

void rotateBoard() {
	int squareSize = 1;
	while (squareSize <= N) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (checkCondition(i,j,squareSize)) {
					int tmp[11][11];
					fill(&tmp[0][0], &tmp[0][0] + 11 * 11, 0);

					for (int k = 0; k < squareSize; k++) {
						for (int l = 0; l <squareSize; l++) {
							//{j, N-1 - i} <- {i,j}
							tmp[i + l][j + squareSize - 1 - k] = board[i + k][j + l];
						}
					}

					for (int k = 0; k < squareSize; k++) {
						for (int l = 0; l < squareSize; l++) {
							board[i + k][j + l] = tmp[i + k][j + l];

							if (board[i + k][j +l] == -1) {
								exitY = i + k;
								exitX = j + l;
							}

							if (board[i + k][j + l] > 0)
								board[i + k][j + l]--;
						}
					}

					rotatePlayer(i, j, squareSize);

					return;
				}
			}
		squareSize++;
	}
}

bool isAllPlayerEscaped() {
	for (int i = 1; i <= M; i++)
		if (isEscaped[i] == false)
			return false;

	return true;
}

void printResult() {
	int sum = 0;

	for (int i = 1; i <= M; i++)
		sum += moveDistance[i];

	cout << sum << "\n" << exitY + 1 << " " << exitX + 1 << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		y--;
		x--;
		playerLocation[i + 1] = { y,x };
	}

	cin >> exitY >> exitX;
	exitY--;
	exitX--;
	board[exitY][exitX] = -1;

	int curTime = 0;

	while (curTime != K) {
		curTime++;

		// 참가자들 동시에 움직임
		moveAll();

		rotateBoard();

		if (isAllPlayerEscaped())
			break;
	}

	printResult();



}