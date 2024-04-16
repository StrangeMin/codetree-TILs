#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, bombCnt;
int board[21][21];
pair<int, int> bomb[11];
int ret;

int dx[3][4] = {
	{0,0,0,0},
	{-1,0,1,0},
	{-1,1,1,-1}
};

int dy[3][4] = {
	{-1,-2,1,2},
	{0,-1,0,1},
	{-1,-1,1,1}
};

bool isAvailableArea(int y, int x, int bombIndex) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[bombIndex][i];
		int nx = x + dx[bombIndex][i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
			return false;
		}
	}
	return true;
}

int getCount() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] > 0)
				cnt++;

	return cnt;
}

void makeBomb(int y, int x, int bombIndex) {
	board[y][x]++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[bombIndex][i];
		int nx = x + dx[bombIndex][i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
			continue;
		}

		board[ny][nx]++;
	}
}

void eraseBomb(int y, int x, int bombIndex) {
	board[y][x]--;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[bombIndex][i];
		int nx = x + dx[bombIndex][i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
			continue;
		}

		board[ny][nx]--;
	}
}


void go(int index) {
	if (index == bombCnt) {
		ret = max(ret, getCount());
		return;
	}
	int y = bomb[index].first;
	int x = bomb[index].second;
	for (int i = 0; i < 3; i++) {
		
		makeBomb(y, x, i);
		go(index + 1);
		eraseBomb(y, x, i);
		
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int cnt = 0;
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			if (num) {
				bomb[cnt++] = { i,j };
				bombCnt++;
			}
		}

	go(0);

	cout << ret << "\n";
}