#include <iostream>
#include <queue>
using namespace std;


int N, M, K;
priority_queue<int> board[21][21];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
pair<int, int> playerBoard[21][21]; // 번호, 방향
int playerAbility[31];
int playerGun[31];
int point[31];

bool isNoOneHere(int y, int x) {
	pair<int, int> empty = { 0,0 };
	return playerBoard[y][x] == empty;
}

bool canMove(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;

	if (!isNoOneHere(y, x))
		return false;

	return true;
}

void move(int index) {
	int y, x;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if (playerBoard[i][j].first == index) {
				y = i;
				x = j;
				break;
			}
	int dir = playerBoard[y][x].second;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
		dir = (dir + 2) % 4;
		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	if (isNoOneHere(ny, nx)) {
		if (board[ny][nx].size()) {
			int userGun = playerGun[index];
			int floorGun = board[ny][nx].top();

			if (floorGun > userGun) {
				board[ny][nx].pop();
				playerGun[index] = floorGun;

				if(userGun != 0)
					board[ny][nx].push(userGun);
			}
		}
		playerBoard[y][x] = { 0,0 };
		playerBoard[ny][nx] = { index, dir };
	}
	else {
		int therePlayerIndex = playerBoard[ny][nx].first;
		int thereDir = playerBoard[ny][nx].second;
		int curPlayerDamage = playerAbility[index] + playerGun[index];
		int therePlayerDamage = playerAbility[therePlayerIndex] + playerGun[therePlayerIndex];

		if (curPlayerDamage > therePlayerDamage) {
			point[index] += curPlayerDamage - therePlayerDamage;

			// cur이 ny,nx로 이동
			playerBoard[y][x] = { 0,0 };
			playerBoard[ny][nx] = { index, dir };

			// there이 총 내려놓음
			// there 이동

			if (playerGun[therePlayerIndex] != 0) {
				board[ny][nx].push(playerGun[therePlayerIndex]);
				playerGun[therePlayerIndex] = 0;
			}

			for (int i = 0; i < 4; i++) {
				int thereY = ny + dy[thereDir];
				int thereX = nx + dx[thereDir];

				if (canMove(thereY, thereX)) {
					playerBoard[thereY][thereX] = { therePlayerIndex, thereDir };

					if (board[thereY][thereX].size()) {
						int therePlayerGun = playerGun[therePlayerIndex];
						int floorGun = board[thereY][thereX].top();

						if (floorGun > therePlayerGun) {
							board[thereY][thereX].pop();
							playerGun[therePlayerIndex] = floorGun;

							if (therePlayerGun != 0)
								board[thereY][thereX].push(therePlayerGun);
						}
					}
					break;
				}
				thereDir = (thereDir + 1) % 4;
			}

			// cur은 바닥총과 비교해서 총 줍고, 가지고 있던 건 내려둠
			if (board[ny][nx].size()) {
				int curPlayerGun = playerGun[index];
				int floorGun = board[ny][nx].top();

				if (floorGun > curPlayerGun) {
					board[ny][nx].pop();
					playerGun[index] = floorGun;

					if (curPlayerGun != 0)
						board[ny][nx].push(curPlayerGun);
				}
			}

		}
		else if(curPlayerDamage < therePlayerDamage) {
			point[therePlayerIndex] += therePlayerDamage - curPlayerDamage;

			// cur의 이전 위치 삭제, there은 그 자리에 있음.
			playerBoard[y][x] = { 0,0 };

			// cur이 총 내려놓음
			// cur 이동

			if (playerGun[index] != 0) {
				board[ny][nx].push(playerGun[index]);
				playerGun[index] = 0;
			}

			for (int i = 0; i < 4; i++) {
				int curY = ny + dy[dir];
				int curX = nx + dx[dir];

				if (canMove(curY, curX)) {
					playerBoard[curY][curX] = { index, dir };

					if (board[curY][curX].size()) {
						int curPlayerGun = playerGun[index];
						int floorGun = board[curY][curX].top();

						if (floorGun > curPlayerGun) {
							board[curY][curX].pop();
							playerGun[index] = floorGun;

							if (curPlayerGun != 0)
								board[curY][curX].push(curPlayerGun);
						}
					}
					break;
				}
				dir = (dir + 1) % 4;
			}

			// there 바닥총과 비교해서 총 줍고, 가지고 있던 건 내려둠
		
			if (board[ny][nx].size()) {
				int therePlayerGun = playerGun[therePlayerIndex];
				int floorGun = board[ny][nx].top();

				if (floorGun > therePlayerGun) {
					board[ny][nx].pop();
					playerGun[therePlayerIndex] = floorGun;

					if (therePlayerGun != 0)
						board[ny][nx].push(therePlayerGun);
				}
			}
		}
		else {
			int curAbility = playerAbility[index];
			int thereAbility = playerAbility[therePlayerIndex];

			if (curAbility > thereAbility) {
				point[index] += curPlayerDamage - therePlayerDamage;

				// cur이 ny,nx로 이동
				playerBoard[y][x] = { 0,0 };
				playerBoard[ny][nx] = { index, dir };

				// there이 총 내려놓음
				// there 이동

				if (playerGun[therePlayerIndex] != 0) {
					board[ny][nx].push(playerGun[therePlayerIndex]);
					playerGun[therePlayerIndex] = 0;
				}

				for (int i = 0; i < 4; i++) {
					int thereY = ny + dy[thereDir];
					int thereX = nx + dx[thereDir];

					if (canMove(thereY, thereX)) {
						playerBoard[thereY][thereX] = { therePlayerIndex, thereDir };

						if (board[thereY][thereX].size()) {
							int therePlayerGun = playerGun[therePlayerIndex];
							int floorGun = board[thereY][thereX].top();

							if (floorGun > therePlayerGun) {
								board[thereY][thereX].pop();
								playerGun[therePlayerIndex] = floorGun;

								if (therePlayerGun != 0)
									board[thereY][thereX].push(therePlayerGun);
							}
						}
						break;
					}
					thereDir = (thereDir + 1) % 4;
				}

				// cur은 바닥총과 비교해서 총 줍고, 가지고 있던 건 내려둠
				if (board[ny][nx].size()) {
					int curPlayerGun = playerGun[index];
					int floorGun = board[ny][nx].top();

					if (floorGun > curPlayerGun) {
						board[ny][nx].pop();
						playerGun[index] = floorGun;

						if (curPlayerGun != 0)
							board[ny][nx].push(curPlayerGun);
					}
				}
			}
			else {
				// cur의 이전 위치 삭제, there은 그 자리에 있음.
				playerBoard[y][x] = { 0,0 };

				// cur이 총 내려놓음
				// cur 이동

				if (playerGun[index] != 0) {
					board[ny][nx].push(playerGun[index]);
					playerGun[index] = 0;
				}

				for (int i = 0; i < 4; i++) {
					int curY = ny + dy[dir];
					int curX = nx + dx[dir];

					if (canMove(curY, curX)) {
						playerBoard[curY][curX] = { index, dir };

						if (board[curY][curX].size()) {
							int curPlayerGun = playerGun[index];
							int floorGun = board[curY][curX].top();

							if (floorGun > curPlayerGun) {
								board[curY][curX].pop();
								playerGun[index] = floorGun;

								if (curPlayerGun != 0)
									board[curY][curX].push(curPlayerGun);
							}
						}
						break;
					}
					dir = (dir + 1) % 4;
				}

				// there 바닥총과 비교해서 총 줍고, 가지고 있던 건 내려둠

				if (board[ny][nx].size()) {
					int therePlayerGun = playerGun[therePlayerIndex];
					int floorGun = board[ny][nx].top();

					if (floorGun > therePlayerGun) {
						board[ny][nx].pop();
						playerGun[therePlayerIndex] = floorGun;

						if (therePlayerGun != 0)
							board[ny][nx].push(therePlayerGun);
					}
				}
			}
		}
	}
}

void printResult() {
	for (int i = 1; i <= M; i++) {
		cout << point[i] << " ";
	}
	cout << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			int damage;
			cin >> damage;
			if (damage)
				board[i][j].push(damage);
		}

	for (int i = 1; i <= M; i++) {
		int y, x, d, s;
		cin >> y >> x >> d >> s;
		y--;
		x--;
		playerBoard[y][x] = { i,d };
		playerAbility[i] = s;
	}

	while (K--) {

		for (int i = 1; i <= M; i++) {
			move(i);
		}
	}

	printResult();
}