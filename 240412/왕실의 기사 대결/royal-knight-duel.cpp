#include <iostream>
#include <map>
#include <queue>
using namespace std;

int L, N, Q;

int board[41][41];
bool visited[41][41];
bool knightVisited[31];
pair<int,int> knight[31];
int knightBoard[41][41];
int nextkNight[41][41];
int lifePoint[31];
int restLifePoint[31];
bool isShiftAvailable;
map<int, int> list;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int ret;

void printNextKnight() {
	cout << "\n";
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			cout << nextkNight[i][j] << " ";
		}
		cout << "\n";
	}
}


void printKnight() {
	cout << "\n";
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			cout << knightBoard[i][j] << " ";
		}
		cout << "\n";
	}
}

void dfs(int y, int x) {
	visited[y][x] = true;
	int knightNumber = knightBoard[y][x];
	knightVisited[knightNumber] = true;
	nextkNight[y][x] = knightNumber;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= L || nx < 0 || nx >= L || visited[ny][nx] || knightNumber != knightBoard[ny][nx]) {
			continue;
		}

		dfs(ny, nx);
	}
}

void shiftKnight(int knightNumber, int dir) {
	isShiftAvailable = true;
	fill(&visited[0][0], &visited[0][0] + 41 * 41, false);
	fill(knightVisited, knightVisited + 31, false);
	fill(&nextkNight[0][0], &nextkNight[0][0] + 41 * 41, 0);

	queue<pair<int, int>> q;
	q.push({knight[knightNumber].first, knight[knightNumber].second});

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		visited[y][x] = true;
		knightVisited[knightBoard[y][x]] = true;
		int curKnightNumber = knightBoard[y][x];
		list[curKnightNumber]++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			int shiftY = y + dy[dir];
			int shiftX = x + dx[dir];

			if (shiftX < 0 || shiftX >= L || shiftY < 0 || shiftY >= L || board[shiftY][shiftX] == 2) {
				isShiftAvailable = false;
				return;
			}

			nextkNight[shiftY][shiftX] = curKnightNumber;


			if (nx < 0 || nx >= L || ny < 0 || ny >= L || board[ny][nx] == 2) {
				continue;
			}

			if (visited[ny][nx] || knightBoard[ny][nx] == 0)
				continue;

			if (dir != i && knightBoard[ny][nx] != curKnightNumber)
				continue;

			q.push({ ny,nx });
			
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!knightVisited[i]) {
			int y = knight[i].first;
			int x = knight[i].second;
			dfs(y, x);
		}
	}
}

void eraseKnight(int y, int x) {
	visited[y][x] = true;
	int knightNumber = knightBoard[y][x];
	knightBoard[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= L || nx < 0 || nx >= L || visited[ny][nx] || knightNumber != knightBoard[ny][nx]) {
			continue;
		}

		eraseKnight(ny, nx);
	}	
}

void calculateDamage(int orderNight) {
	if (!isShiftAvailable) {
		list.clear();
		return;
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			int knightNumber = nextkNight[i][j];
			knightBoard[i][j] = knightNumber;

			if (knightNumber == 0)
				continue;

			knight[knightNumber] = { i,j };

			if (knightNumber == orderNight)
				continue;

			if (board[i][j] == 1 && list[knightNumber] != 0)
				restLifePoint[knightNumber] -= 1;

			if (restLifePoint[knightNumber] <= 0) {
				fill(&visited[0][0], &visited[0][0] + 41 * 41, false);
				eraseKnight(i, j);
			}
		}
	}
	list.clear();
}

void printResult() {
	for (int i = 1; i <= N; i++) {
		if (restLifePoint[i] > 0)
			ret += lifePoint[i] - restLifePoint[i];
	}

	cout << ret << "\n";
}

void printScore() {
	cout << "\n";
	for (int i = 1; i <= N; i++)
		cout << restLifePoint[i] << " ";
	cout << "\n";
}

void order(int knightNumber, int dir) {
	if (restLifePoint[knightNumber] <= 0)
		return;

	// 한 칸 옮길 기사들 찾고, 한 칸씩 이동
	shiftKnight(knightNumber, dir);

	// 데미지 계산
	calculateDamage(knightNumber);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> N >> Q;

	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		int r, c, h, w, k;
		cin >> r >> c >> h >> w >> k;
		r--; c--;
		knight[i + 1] = { r,c };

		for (int j = r; j < r + h; j++)
			for (int k = c; k < c + w; k++)
				knightBoard[j][k] = i + 1;

		lifePoint[i + 1] = k;
		restLifePoint[i + 1] = k;
	}

	for (int i = 0; i < Q; i++) {
		int knightNumber, dir;
		cin >> knightNumber >> dir;

		order(knightNumber, dir);
	}

	printResult();
}