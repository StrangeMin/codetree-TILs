#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int main() {
    
    int num;
    string str;

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> str;

        m[str]++;
    }

    int ret =0;

    for(auto it : m){
        ret = max(ret, it.second);
    }

    cout << ret << "\n";

    return 0;
}