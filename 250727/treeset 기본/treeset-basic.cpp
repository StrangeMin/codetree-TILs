#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
string command[100000];
int x[100000];
set<int> s;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command[i];

        // x가 필요한 명령어인 경우 x 입력 받기
        if (command[i] == "add" || command[i] == "remove" || command[i] == "find" || 
            command[i] == "lower_bound" || command[i] == "upper_bound") {
            cin >> x[i];
        }

        if (command[i] == "add") {
            s.insert(x[i]);
        }
        else if (command[i] == "remove") {
            s.erase(x[i]);
        }
        else if (command[i] == "find") {
            if (s.find(x[i]) != s.end()) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }
        else if (command[i] == "lower_bound") {
            auto it = s.lower_bound(x[i]);
            if (it != s.end()) {
                cout << *it << "\n";
            } else {
                cout << "None\n";
            }
        }
        else if (command[i] == "upper_bound") {
            auto it = s.upper_bound(x[i]);
            if (it != s.end()) {
                cout << *it << "\n";
            } else {
                cout << "None\n";
            }
        }
        else if (command[i] == "largest") {
            if (!s.empty()) {
                cout << *s.rbegin() << "\n";
            } else {
                cout << "None\n";
            }
        }
        else if (command[i] == "smallest") {
            if (!s.empty()) {
                cout << *s.begin() << "\n";
            } else {
                cout << "None\n";
            }
        }
    }

    return 0;
}
