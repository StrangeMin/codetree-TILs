#include <iostream>
#include <string>

using namespace std;

int N;
int ret;

bool isBeautifulNumber(string str) {
	int index = 0;

	while (index < N) {
		if(str[index] == '1'){
			index += 1;
		}
		else if (str[index] == '2') {
			int lastIndex = index + 1;

			if (lastIndex >= N)
				return false;

			for (int i = index; i <= lastIndex; i++) {
				if (str[i] != '2')
					return false;
			}

			index = lastIndex + 1;
		}
		else if (str[index] == '3') {
			int lastIndex = index + 2;

			if (lastIndex >= N)
				return false;

			for (int i = index; i <= lastIndex; i++) {
				if (str[i] != '3')
					return false;
			}

			index = lastIndex + 1;
		}
		else if (str[index] == '4') {
			int lastIndex = index + 3;

			if (lastIndex >= N)
				return false;

			for (int i = index; i <= lastIndex; i++) {
				if (str[i] != '4')
					return false;
			}

			index = lastIndex + 1;
		}
	}

	return true;
}

void go(int index, string str) {
	if (index == N) {
		if (isBeautifulNumber(str))
			ret++;

		return;
	}

	for (int i = 1; i <= 4; i++) {
		go(index + 1, str + to_string(i));
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string str = "";

	go(0,str);

	cout << ret << "\n";
}