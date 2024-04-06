#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <deque>
using namespace std;

int N, M, K;
int board[101][101];
bool visited[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool done;
map<char, int> dir;
deque<pair<int, int>> snake;
int t;

void move(int d) {
	t++;
	int y = snake.front().first;
	int x = snake.front().second;

	int lastY = snake.back().first;
	int lastX = snake.back().second;
	visited[lastY][lastX] = false;
	snake.pop_back();

	int ny = y + dy[d];
	int nx = x + dx[d];

	if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
		done = true;
		return;
	}

	snake.push_front({ ny,nx });
	visited[ny][nx] = true;

	if (board[ny][nx] == 2) {
		board[ny][nx] = 0;
		snake.push_back({ lastY, lastX });
	}	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	dir['L'] = 0;
	dir['U'] = 1;
	dir['R'] = 2;
	dir['D'] = 3;
	visited[0][0] = true;
	snake.push_back({ 0,0 });

	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		y--; x--;
		board[y][x] = 2;
	}

	for (int i = 0; i < K; i++) {
		char d;
		int amount;
		cin >> d >> amount;

		while (amount--) {
			move(dir[d]);
			if (done)
				break;
		}
		if (done)
			break;
	}

	cout << t << "\n";

}