#include <iostream>
#include <unordered_map>
using namespace std;

long long n, k;
long long arr[100000];
unordered_map<long long,long long> m;
long long ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    for(auto it : m){
        long long tmp = k - it.first;

        if(tmp == it.first){
            ret += (it.second *(it.second-1))/2;
            m[tmp] = 0;
        }
        else if(m.find(tmp) != m.end()){
            ret += it.second * m[tmp];
            m[tmp] = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}
