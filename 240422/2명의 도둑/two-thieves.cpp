#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, C, ret = INT_MIN;
int board[11][11];

int go(int row, int curIndex, int lastIndex, int sum, int weight) {
	if (curIndex > lastIndex) {
		return sum;
	}
	int tmp, tmp2;
	int curWeight = board[row][curIndex];
	if (weight + curWeight <= C) {
		tmp = go(row, curIndex + 1, lastIndex, sum + curWeight * curWeight, weight + curWeight);
	}
	else
		tmp = sum;

	tmp2 = go(row, curIndex + 1, lastIndex, sum, weight);

	return max(tmp, tmp2);
}

bool checkOverlap(int k, int M, int l) {
	// k와 l 중 작은 값이 시작점이 되도록 설정
	int start1 = std::min(k, l);
	int start2 = (start1 == k) ? l : k;

	// 두 구간이 겹치는지 확인
	return start1 == start2 || start1 + M - 1 >= start2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> C;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {

					if (k + M  -1 > N || l + M - 1 > N)
						continue;
					
					if (i==j && checkOverlap(k,M,l))
						continue;

					int robber1 = go(i, k, k + M - 1, 0, 0);
					int robber2 = go(j, l, l + M -1, 0, 0);
					ret = max(ret, robber1 + robber2);
				}
			}

		}
	}

	cout << ret << "\n";
}