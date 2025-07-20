#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string command[100000];
int x[100000];
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];

        if(command[i] == "add"){
            s.insert(x[i]);
        }
        else if(command[i] == "remove"){
            s.erase(x[i]);
        }
        else if(command[i] == "find"){
            auto it =s.find(x[i]);
            if(it == s.end())
                cout << "false\n";
            else
                cout << "true\n";
        }
    }

    // Please write your code here.

    return 0;
}
