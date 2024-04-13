#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
pair<int,int> board[11][11];
bool visited[11][11];
pair<int, int> parent[11][11];
bool isAvailableRepair[11][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

pair<int, int> selectAttacker() {
	int damage = 5001;
	int y=0, x=0;
	int latelyAttackTime = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int curDamage = board[i][j].first;
			int curLatelyAttackTime = board[i][j].second;

			if (curDamage == 0)
				continue;

			if (curDamage < damage) {
				damage = curDamage;
				y = i;
				x = j;
				latelyAttackTime = curLatelyAttackTime;
			}
			else if (curDamage == damage) {
				if (curLatelyAttackTime > latelyAttackTime) {
					damage = curDamage;
					y = i;
					x = j;
					latelyAttackTime = curLatelyAttackTime;
				}
				else if (curLatelyAttackTime == latelyAttackTime) {
					if (i + j > y + x) {
						damage = curDamage;
						y = i;
						x = j;
						latelyAttackTime = curLatelyAttackTime;
					}
					else if (i + j == y + x) {
						if (j > x) {
							damage = curDamage;
							y = i;
							x = j;
							latelyAttackTime = curLatelyAttackTime;
						}
					}
				}
			}
		}
	}
	return { y,x };
}

pair<int, int> selectTarget() {
	int damage = -1;
	int y = 0, x = 0;
	int latelyAttackTime = 1001;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int curDamage = board[i][j].first;
			int curLatelyAttackTime = board[i][j].second;

			if (curDamage > damage) {
				damage = curDamage;
				y = i;
				x = j;
				latelyAttackTime = curLatelyAttackTime;
			}
			else if (curDamage == damage) {
				if (curLatelyAttackTime < latelyAttackTime) {
					damage = curDamage;
					y = i;
					x = j;
					latelyAttackTime = curLatelyAttackTime;
				}
				else if (curLatelyAttackTime == latelyAttackTime) {
					if (i + j < y + x) {
						damage = curDamage;
						y = i;
						x = j;
						latelyAttackTime = curLatelyAttackTime;
					}
					else if (i + j == y + x) {
						if (j < x) {
							damage = curDamage;
							y = i;
							x = j;
							latelyAttackTime = curLatelyAttackTime;
						}
					}
				}
			}
		}
	}
	return { y,x };
}

void findPath(int y, int x) {
	queue <pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = (cx + dx[i] + M) % M;
			int ny = (cy + dy[i] + N) % N;

			if (visited[ny][nx] || board[ny][nx].first == 0)
				continue;

			parent[ny][nx] = { cy,cx };
			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
}



void attack(pair<int, int> attacker, pair<int,int> target, int curTime) {
	fill(&visited[0][0], &visited[0][0] + 11 * 11, false);
	fill(&isAvailableRepair[0][0], &isAvailableRepair[0][0] + 11 * 11, true);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			parent[i][j] = { -1,-1 };


	findPath(attacker.first, attacker.second);
	int damage = board[attacker.first][attacker.second].first + N + M;
	board[attacker.first][attacker.second] = { damage,curTime };

	if (visited[target.first][target.second]) {
		int curY = target.first;
		int curX = target.second;

		while (!(curY == attacker.first && curX == attacker.second)) {
			
			if (curY == target.first && curX == target.second) {
				board[curY][curX] = { max(board[curY][curX].first - damage,0), board[curY][curX].second };
			}
			else {
				board[curY][curX] = { max((board[curY][curX].first - damage/2),0), board[curY][curX].second };
			}
			isAvailableRepair[curY][curX] = false;
			
			int nextY = parent[curY][curX].first;
			int nextX = parent[curY][curX].second;

			curY = nextY;
			curX = nextX;
		}

		isAvailableRepair[curY][curX] = false;
	} 
	else {
		// 공격포탑 수리불가능
		isAvailableRepair[attacker.first][attacker.second] = false;

		// 타겟 공격
		int curY = target.first;
		int curX = target.second;
		board[curY][curX] = { max(board[curY][curX].first - damage,0), board[curY][curX].second };
		isAvailableRepair[curY][curX] = false;

		// 주변 공격
		int DX[8] = { -1,-1,0,1,1,1,0,-1 };
		int DY[8] = { 0,-1,-1,-1,0,1,1,1 };
		for (int i = 0; i < 8; i++) {
			int nx = curX + DX[i];
			int ny = curY + DY[i];

			if (nx < 0)
				nx = M - 1;
			if (ny < 0)
				ny = N - 1;

			nx %= M;
			ny %= N;

			if (board[ny][nx].first > 0) {
				board[ny][nx] = { max((board[ny][nx].first - damage/2),0), board[ny][nx].second };
				isAvailableRepair[ny][nx] = false;
			}

		}

	}

}

void repair() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j].first > 0 &&  isAvailableRepair[i][j]) {
				board[i][j] = { board[i][j].first + 1, board[i][j].second };
			}
		}
	}
}

bool checkTerminationCondition() {
	int restCnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j].first > 0)
				restCnt++;

			if (restCnt >= 2)
				return false;
		}
	}

	return true;
}

void printDamage() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j].first << " ";
		}
		cout << "\n";
	}
}

int getMaxDamage() {
	int damage = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			damage = max(damage, board[i][j].first);

	return damage;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int damage;
			cin >> damage;
			board[i][j] = { damage, 0 };
		}

	int curTime = 0;
	while (curTime != K) {
		curTime++;

		pair<int,int> attacker = selectAttacker();
		pair<int,int> target = selectTarget();
		attack(attacker, target, curTime);

		repair();

		if (checkTerminationCondition())
			break;

	}

	cout << getMaxDamage() << "\n";
}