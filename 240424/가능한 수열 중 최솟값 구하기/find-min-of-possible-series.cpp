#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, sy,sx;
int board[5][5];
int direction[5][5];
int dx[8] = { 0,1,1,1,0,-1, - 1, - 1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
string ret;
bool done;

bool isAvailable(string str) {
	int len = 1;
	int rightEnd = str.size() - 1;

	while (true) {
		int rightStart = rightEnd - len + 1;
		int leftEnd = rightStart - 1;
		int leftStart = leftEnd - len + 1;
		if (leftStart < 0)
			break;

		if (str.substr(leftStart, len) == str.substr(rightStart, len))
			return false;
		len++;
	}


	return true;
}

void go(string str) {
	if (str.size() == N) {
		ret = str;
		done = true;
		return;
	}

	for (int i = 4; i <= 6; i++) {

		if (isAvailable(str + to_string(i))) {
			go(str + to_string(i));
		}


		if (done)
			return;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	

	go("4");

	cout << ret << "\n";

	return 0;
}