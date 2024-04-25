#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
bool visited[11];
int board[11][11];
int ret = INT_MAX;

void go(int index, int sum, int prev) {
	if (index == N-1) {
		ret = min(ret, sum + board[prev][0]);
		return;
	}

	for (int i = 1; i < N; i++){
		if (visited[i] || board[prev][i] == 0)
			continue;

		visited[i] = true;
		go(index + 1, sum + board[prev][i], i);
		visited[i] = false;
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	visited[0] = true;
	go(0,0,0);

	cout << ret << "\n";
}