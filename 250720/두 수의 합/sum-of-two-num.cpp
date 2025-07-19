#include <iostream>
#include <unordered_map>
#define long long ll;
using namespace std;

int n, k;
int arr[100000];
unordered_map<int,int> m;
int ret;

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    for(auto it : m){
        int tmp = k - it.first;

        if(m[tmp] != 0){
            ret += it.second;
            m[tmp] = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}
