#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K;
bool row[11];
bool column[11];
int board[11][11];
int ret = INT_MIN;

void go(int index, int sum, int minimum) {
	if (index == N - 1) {
		for (int i = 0; i < N; i++) {
			if (column[i])
				continue;

			int tmp = min(minimum, board[index][i]);

			ret = max(ret, tmp);
			break;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (column[i])
			continue;

		column[i] = true;
		go(index + 1, sum + board[index][i], min(minimum, board[index][i]));
		column[i] = false;
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

	go(0, 0, INT_MAX);

	cout << ret << "\n";
}