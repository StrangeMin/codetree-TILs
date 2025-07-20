#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long, long> m;
int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];
int ret;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    for (int i = 0; i < n; i++) cin >> C[i];

    for (int i = 0; i < n; i++) cin >> D[i];

    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            int tmpSum = A[i] + B[j];
            m[tmpSum]++;    
        }
    }

    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            int diff = -1 * (C[i] + D[j]);

            if(m.find(diff) != m.end()){
                ret += m[diff];
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
