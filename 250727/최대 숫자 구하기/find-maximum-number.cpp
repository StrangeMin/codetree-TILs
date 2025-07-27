#include <iostream>
#include <set>

using namespace std;

int n, m;
int queries[100000];
set<int> s;
int main() {
    cin >> n >> m;

    for(int i=1; i<=m; i++)
        s.insert(i);

    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        s.erase(queries[i]);

        cout << *s.rbegin() << "\n";
    }


    return 0;
}
