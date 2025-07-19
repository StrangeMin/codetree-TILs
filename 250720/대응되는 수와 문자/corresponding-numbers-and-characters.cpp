#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int n, m;
string words[100000];
string queries[100000];
map<string, int> a;

bool isNumber(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        a[words[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];

        if(isNumber(queries[i])){
            cout << words[stoi(queries[i])] << "\n";
        }
        else{
            cout << a[queries[i]] << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
