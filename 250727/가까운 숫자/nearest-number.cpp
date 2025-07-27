#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int queries[100000];
set<int> s;
int ret = INT_MAX;

int main() {
    cin >> n;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        
        auto it = s.upper_bound(queries[i]);

        if(it == s.end()){
            ret = min(ret, abs(*--it - queries[i]));
        }
        else{
            int next = *it;
            int prev = *--it;

            ret = min(ret, min(abs(queries[i] - next), abs(queries[i] - prev)));
        }

        cout << ret << "\n";
        s.insert(queries[i]);
    }

    // Please write your code here.

    return 0;
}
