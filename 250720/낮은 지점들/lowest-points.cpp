#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x[100000], y[100000];
unordered_map<long long,long long> m;
long long ret;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        auto it = m.find(x[i]);

        if(it == m.end()){
            m[x[i]] = y[i];
        }
        else if(it->second > y[i]){
            m[x[i]] = y[i];
        }
    }

    for(auto it : m){
        ret += it.second;
    }

    cout << ret << "\n";

    return 0;
}