#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[10000];
map<string, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]]++;
    }
    
    cout << fixed; //소수점 고정
	cout.precision(4);

    for(auto it : m){
        cout << it.first << " " << (it.second/(double)n) * 100 << "\n";
    }

    // Please write your code here.

    return 0;
}
