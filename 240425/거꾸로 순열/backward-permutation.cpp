#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, K, ret;
bool visited[9];

void go(int index, vector<int> v) {
	if (index == N-1) {
		for (int i = N; i >= 1; i--) {
			if (visited[i])
				continue;

			for (auto e : v) {
				cout << e << " ";
			}

			cout << i << "\n";
		}
		return;
	}

	for (int i = N; i >= 1; i--) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			go(index + 1, v);
			v.pop_back();
			visited[i] = false;

		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> v;
	go(0,v);

	//cout << ret << "\n";
}