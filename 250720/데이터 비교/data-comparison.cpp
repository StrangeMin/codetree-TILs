#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];
unordered_set<int> s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        s.insert(arr1[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        if(s.find(arr2[i]) == s.end())
            cout << 0 << " ";
        else
            cout << 1 << " ";
    }
    cout << "\n";
    

    return 0;
}
