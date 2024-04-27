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
int sy, sx;
int maxNum;
vector<pair<int, int>> candidate;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

void dfs(int y, int x, int num) {
	if (board[y][x] < num) {
		
		if (maxNum == board[y][x]) {
			candidate.push_back({ y,x });
		}
		else if (maxNum < board[y][x]) {
			candidate.clear();
			candidate.push_back({ y,x });
			maxNum = board[y][x];
		}
	}
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || board[ny][nx] >= num)
			continue;

		dfs(ny, nx, num);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K ;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cin >> sy >> sx;
	sy--; sx--;

	for (int i = 0; i < K; i++) {
		maxNum = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
		candidate.clear();
		dfs(sy, sx, board[sy][sx]);

		if (!candidate.size())
			break;

		sort(candidate.begin(), candidate.end(), cmp);
		sy = candidate[0].first;
		sx = candidate[0].second;
	}

	cout << sy +1 << " " << sx + 1 << "\n";
}