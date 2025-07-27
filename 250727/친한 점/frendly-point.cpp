#include <iostream>
#include <set>

using namespace std;

int n, m;
int x[100000], y[100000];
int qx[100000], qy[100000];
set<pair<int,int>> s;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        s.insert({x[i],y[i]});
    }

    for (int i = 0; i < m; i++) {
        cin >> qx[i] >> qy[i];
        auto it = s.lower_bound({qx[i], qy[i]});

        if(it == s.end())
            cout << -1 << " " << -1 << "\n";
        else
            cout << it->first << " " << it->second << "\n";
    };

    // Please write your code here.

    return 0;
}
