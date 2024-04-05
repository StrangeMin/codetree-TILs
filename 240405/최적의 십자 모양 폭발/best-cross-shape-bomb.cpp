#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int N;
int board[51][51];
bool visited[51][51];
int dx[4] = {-1,0,1,0 };
int dy[4] = {0,-1,0,1 };
int tmp[51][51];
int ret = INT_MIN;

void initBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}

int getSameNumberAreaCnt(int y, int x) {
	int cur = tmp[y][x];
	if (cur == 0)
		return 0;

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || tmp[ny][nx] != cur)
			continue;

		cnt++;
	}
	return cnt;
}

void explosion(int y, int x) {
	int curNum = board[y][x];
	
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			if ((i == y || j == x) && (abs(i - y) + abs(j - x) < curNum)) {
				tmp[i][j] = 0;
			}
			else {
				tmp[i][j] = board[i][j];
			}
		}
}

void printBoard() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << tmp[i][j] << " ";
		cout << "\n";
	}
}


void gravity() {
	int tmpArr[51][51];
	fill(&tmpArr[0][0], &tmpArr[0][0] + 51 * 51, 0);

	for (int i = 0; i < N; i++) {
		int curRow = N-1;
		for (int j = N-1; j >= 0; j--) {
			if (tmp[j][i] != 0) {
				tmpArr[curRow--][i] = tmp[j][i];
			}
		}
	}
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = tmpArr[i][j];
}


int getRet() {
	int sum = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum += getSameNumberAreaCnt(i, j);
	return sum/2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N ;

	initBoard();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			explosion(i, j);
			gravity();
			ret = max(ret, getRet());
		}
	}

	cout << ret << "\n";
}