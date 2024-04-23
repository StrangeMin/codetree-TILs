#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M, C, ret = INT_MIN;
int board[11][11];
string str;
int alpha[26];

int calculate(int sum, char op, int num) {
	if (op == '+')
		return sum + num;
	else if (op == '-')
		return sum - num;
	else if (op == '*')
		return sum * num;

}

void go(int index, int sum) {
	if (index == str.size() - 1) {
		ret = max(ret, sum);
		return;
	}

	if (alpha[str[index + 2] - 'a']) {
		go(index + 2, calculate(sum, str[index + 1], alpha[str[index + 2] - 'a']));
	}
	else {
		for (int i = 1; i <= 4; i++) {
			alpha[str[index + 2] - 'a'] = i;
			go(index + 2, calculate(sum, str[index + 1], i));
			alpha[str[index + 2] - 'a'] = 0;
		}
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (int i = 1; i <= 4; i++) {
		alpha[str[0] - 'a'] = i;
		go(0, i);
		alpha[str[0] - 'a'] = 0;
	}

	cout << ret << "\n";
}