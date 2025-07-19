#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
map<int,int> m;


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        int k, v;
        if (cmd[i] == "add") {
            cin >> k >> v;
            m[k] = v;
        }
        else if(cmd[i] == "remove"){
            cin >> k;
            m.erase(k);
        }
        else if(cmd[i] == "find"){
            cin >> k;
            auto it = m.find(k);
            if(it == m.end()){
                cout << "None\n";
            }
            else {
                cout << m[k] << "\n";
            }
        }
    
    }

    // Please write your code here.

    return 0;
}
