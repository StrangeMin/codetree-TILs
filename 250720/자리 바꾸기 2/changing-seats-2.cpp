#include <iostream>
#include <unordered_set>
using namespace std;

int N, K;
int a[100000], b[100000];
int sit[100001];
unordered_set<int> s[100001];
void swap(int x1, int x2){
    int tmp = sit[x1];
    sit[x1] = sit[x2];
    sit[x2] = tmp;
}

int main() {
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        sit[i] = i;
        s[i].insert(i);
    } 

    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i=0; i<3*K; i++){
        int man1 = sit[a[i % K]]; // a[i] 번째 사람의 번호
        int man2 = sit[b[i % K]]; // b[i] 번째 사람의 번호

        s[man1].insert(b[i % K]);
        s[man2].insert(a[i % K]);
        swap(a[i % K], b[i % K]);
    }

    for(int i=1; i<=N; i++){
        cout << s[i].size() << "\n";
    }



    return 0;
}
