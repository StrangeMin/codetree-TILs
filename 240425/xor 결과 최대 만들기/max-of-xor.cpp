#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ret;
vector<int> candidate;


void combi(int start, vector<int> v) {
    if (v.size() == M) {
        int num = v[0];
        for (int i = 1; i < v.size(); i++) {
            num ^= v[i];
        }
        ret = max(ret, num);
        return;
    }

    for (int i = start + 1; i < N; i++) {
        v.push_back(candidate[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        candidate.push_back(num);
    }
    vector<int> v;
    combi(-1, v);

    cout << ret << "\n";

    return 0;
}