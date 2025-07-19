#include <iostream>
#include <map>
using namespace std;

int n, k;
int arr[100000];
map<long long,long long> m;
long long ret;

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    for(auto it : m){
        long long tmp = k - it.first;

        if(tmp == it.first){
            ret += (it.second *(it.second-1))/2;
        }
        else if(m[tmp] != 0){
            ret += it.second * m[tmp];
            m[tmp] = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}
