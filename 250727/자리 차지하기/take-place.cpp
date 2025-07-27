#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int a[100000];
set<int> s;
int ret;

int main() {
    cin >> n >> m;

    for(int i=1;i<=n; i++)
        s.insert(i);


    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if(!s.size())
            break;

        auto it = s.lower_bound(a[i]);

        if(it == s.end()){
            s.erase(*--it);
            ret++;
        }
        else{
            if(it == s.begin() && *it > a[i])
                break;
            else if(*it == a[i])
                s.erase(a[i]);
            else 
                s.erase(*--it);
            
            ret++;
        }
    }

    cout << ret << "\n";

    // Please write your code here.

    return 0;
}
