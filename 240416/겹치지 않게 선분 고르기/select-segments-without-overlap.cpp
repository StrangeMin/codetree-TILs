#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, ret;
pair<int, int> line[16];
int linear[1001];

bool canDraw(int start, int end) {
	for (int i = start; i <= end; i++) {
		if (linear[i])
			return false;
	}

	return true;
}

void drawLine(int start, int end) {
	for (int i = start; i <= end; i++) {
		linear[i]++;
	}
}

void eraseLine(int start, int end) {
	for (int i = start; i <= end; i++) {
		linear[i]--;
	}
}

void go(int index, int cnt) {
	if (index == N) {
		ret = max(ret, cnt);
		return;
	}
	int start = line[index].first;
	int end = line[index].second;

	if (canDraw(start,end)) {
		drawLine(start, end);
		go(index + 1, cnt + 1);
		eraseLine(start,end);
	}
	go(index + 1, cnt);
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		line[i] = { start, end };
	}

	go(0, 0);

	cout << ret << "\n";
}