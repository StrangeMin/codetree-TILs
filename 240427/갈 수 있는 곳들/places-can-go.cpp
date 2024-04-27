#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
bool row[11];
bool column[11];
int board[101][101];
bool visited[101][101];
int ret ;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int y, int x) {
	visited[y][x] = true;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || board[ny][nx] == 1)
			continue;

		cnt += dfs(ny, nx);
	}

	return cnt + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K ;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	vector<pair<int, int>> candidate;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		y--; x--;
		candidate.push_back({ y,x });
	}

	for (auto e : candidate) {
		int y = e.first;
		int x = e.second;

		if (!visited[y][x])
			ret += dfs(y, x);
	}

	cout << ret << "\n";
}