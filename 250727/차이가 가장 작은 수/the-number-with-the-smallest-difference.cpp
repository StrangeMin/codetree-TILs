#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int ret = INT_MAX;
set<int> s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        auto it = s.lower_bound(arr[i] + m);

        if(it == s.end())
            continue;

        ret = min(ret, *it - arr[i]);
    }

    if(ret == INT_MAX)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}
