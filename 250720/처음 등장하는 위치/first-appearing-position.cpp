#include <iostream>
#include <map>

using namespace std;

int n;
int arr[100000];
map<int,int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(m.find(arr[i]) == m.end()){
            m[arr[i]] = i+1;
        }
    }

    for(auto it : m){
        cout << it.first << " " << it.second << "\n";
    }

    // Please write your code here.

    return 0;
}
