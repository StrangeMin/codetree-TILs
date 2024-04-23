#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K, ret;
int token [13];
string str;
int alpha[26];
vector<int> movingDistance;

void go(int index) {
	if (index == movingDistance.size()) {
		int tmp = 0;
		for (int i = 0; i < K; i++) {
			if (token[i] >= M - 1)
				tmp++;
		}
		ret = max(ret, tmp);
		return;
	}

	for (int i = 0; i < K; i++) {
		token[i] += movingDistance[index];
		go(index + 1);
		token[i] -= movingDistance[index];
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		movingDistance.push_back(num);
	}

	go(0);

	cout << ret << "\n";
}