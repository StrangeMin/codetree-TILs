#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[100000];
map<string,int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]]++;
    }

    for(auto it : m){
        cout << it.first << " " << it.second << "\n";
    }

    // Please write your code here.

    return 0;
}
