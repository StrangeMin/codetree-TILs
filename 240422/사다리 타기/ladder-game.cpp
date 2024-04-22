#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M,ret = INT_MAX;
int bridge[17][13][13];
int destination[13];
int nextBridge[17][13][13];
int nextDestination[13];
vector<pair<int, int>> candidate;

int goToNextBottom(int index) {
	int curIndex = index;
	for (int i = 0; i <= 15; i++) {

		if (curIndex > 0 && nextBridge[i][curIndex][curIndex - 1]) {
			curIndex = curIndex - 1;
		}
		else if (nextBridge[i][curIndex][curIndex + 1]) {
			curIndex = curIndex + 1;
		}
	}
	return curIndex;
}

void setNextDestination(int index) {
	int curIndex = index;
	nextDestination[index] = goToNextBottom(curIndex);
}

bool isSame() {
	for (int i = 1; i <= N; i++)
		if (destination[i] != nextDestination[i])
			return false;

	return true;
}

void go(int index, int cnt) {
	if (index == M) {
		fill(nextDestination, nextDestination + 12, 0);
		for (int i = 1; i <= N; i++) {
			setNextDestination(i);
		}
		if(isSame())
			ret = min(ret, cnt);

		return;
	}

	int column = candidate[index].first;
	int row = candidate[index].second;

	nextBridge[row][column][column + 1] = 1;
	nextBridge[row][column+1][column] = 1;

	go(index + 1, cnt + 1);

	nextBridge[row][column][column + 1] = 0;
	nextBridge[row][column + 1][column] = 0;

	go(index + 1, cnt);
}

int goToBottom(int index) {
	int curIndex = index;
	for (int i = 0; i <= 15; i++) {

		if (curIndex > 0 && bridge[i][curIndex][curIndex - 1]) {
			curIndex = curIndex - 1;
		}
		else if (bridge[i][curIndex][curIndex + 1]) {
			curIndex = curIndex + 1;
		}
	}
	return curIndex;
}

void setDestination(int index) {
	int curIndex = index;
	destination[index] = goToBottom(curIndex);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int column, row;
		cin >> column >> row;
		row--;
		bridge[row][column][column + 1] = 1;
		bridge[row][column+1][column] = 1;
		candidate.push_back({ column, row });
	}

	for (int i = 1; i <= N; i++) {
		setDestination(i);
	}

	go(0, 0);

	cout << ret << "\n";
}