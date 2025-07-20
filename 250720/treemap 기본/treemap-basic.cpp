#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];
map<int,int> m;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];
            m[k[i]] = v[i];
        } else if (cmd[i] == "remove") {
            cin >> k[i];
            m.erase(k[i]);
        }
        else if(cmd[i] == "find"){
            cin >> k[i];
            auto it = m.find(k[i]);
            if(it == m.end()){
                cout << "None\n";
            }
            else{
                cout << it->second << "\n";
            }
        }
        else if(cmd[i] == "print_list"){
            if(m.size() == 0)
                cout << "None\n";
            else{
                for(auto it : m)
                    cout << it.second << " ";
                cout << "\n";
            }
        }
    }

    // Please write your code here.

    return 0;
}
