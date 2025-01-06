#include <iostream>
using namespace std;

int ret[20];
int N;

int getCount(int n){
    if(ret[n] != 0)
        return ret[n];

    int cnt = 0;

    for(int i=0; i<n; i++){
        cnt += ret[i] * ret[n-1-i];
    }

    ret[n] = cnt;
    return ret[n];
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ret[0] = 1;
    ret[1] = 1;
    ret[2] = 2;

    cin >> N;

    for(int i=3; i<=N; i++){
        getCount(i);
    }

    cout << ret[N] << "\n";

    // 1 : 1
    // 2 : 2

    return 0;
}