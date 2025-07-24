#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int A[200000];
int B[200000];
unordered_set<int> a,b;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        a.insert(A[i]);
    };

    for (int i = 0; i < m; i++) {
        cin >> B[i];

        auto it = a.find(B[i]);

        if(it == a.end()){
            b.insert(B[i]);
        }
        else{
            a.erase(B[i]);
        }
    };

    cout << a.size() + b.size() << "\n";

    return 0;
}
