#include <iostream>

using namespace std;

int n;
int ret[1001];

int getCnt(int N){
    if(ret[N]){
        return ret[N];
    }

    int cnt = 0;
    
    cnt += (getCnt(N-1) + 2 * getCnt(N-2)) % 10007;

    // 새로 막대기를 넣는 경우
    // 가로 막대기를 넣는 경우
    // 정사각형을 넣는 경우

    ret[N] = cnt;

    return cnt;
}

int main() {
    cin >> n;

    ret[1] = 1;
    ret[2] = 3;

    getCnt(n);

    cout << ret[n] << "\n";
    // Write your code here!

    return 0;
}
