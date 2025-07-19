#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string words[1000];
unordered_map<string, int> m;
int ret;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for(int i=0; i<n; i++){
        vector<char> v;
        for(int j=0; j<words[i].size(); j++){
            v.push_back(words[i][j]);
        }
        sort(v.begin(), v.end());
        string tmp ="";

        for(int j=0; j<v.size(); j++){
            tmp += v[j];
        }
        m[tmp]++;
    }

    for(auto it : m){
        ret =max(it.second, ret);
    }

    cout << ret << "\n";

    return 0;
}
