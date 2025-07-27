#include <iostream>
#include <string>
#include <set>

using namespace std;

int n, m;
int P[100000], L[100000];
set<pair<int,int>> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i] >> L[i];
        s.insert({L[i], P[i]});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "rc") {
            int x;
            cin >> x;
            if(x == 1)
                cout << s.rbegin()->second << "\n";
            else
                cout << s.begin()->second << "\n";
        } else if (command == "ad") {
            int p, l;
            cin >> p >> l;
            s.insert({l,p});
        } else if (command == "sv") {
            int p, l;
            cin >> p >> l;
            s.erase({l,p});
        }
    }

    // Please write your code here.

    return 0;
}
