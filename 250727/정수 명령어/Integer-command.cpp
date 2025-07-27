#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char command[100000];
int n[100000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        set<int> s;
        for (int i = 0; i < k; i++) {
            cin >> command[i] >> n[i];

            if(command[i] == 'I'){
                s.insert(n[i]);
            }
            else if(command[i] == 'D' && s.size()){
                if(n[i] == -1){
                    auto it = s.begin();
                    s.erase(*it);
                }
                else{
                    auto it = s.rbegin();
                    s.erase(*it);
                }
            }
        }
        if(s.size()){
            cout << *s.rbegin() << " " << *s.begin() << "\n";
        }
        else{
            cout << "EMPTY\n";
        }

    }

    return 0;
}
