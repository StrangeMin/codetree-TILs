#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[100000];
int queries[100000];
set<int> s;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];

        auto it = s.lower_bound(queries[i]);

        if(it == s.end())
            cout << -1 << "\n";
        else
            cout << *it << "\n";

    }

    // Please write your code here.

    return 0;
}
