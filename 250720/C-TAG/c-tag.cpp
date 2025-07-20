#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <string>

using namespace std;

int n, m;
string A[500];
string B[500];
vector<tuple<int,int,int>> t;
vector<int> orderedTuple;
int ret;
unordered_set<string> s;

void combi(int start, vector<int> v){
    if(v.size() == 3){
        t.push_back(make_tuple(v[0], v[1], v[2]));
        return;
    }

    for(int i=start+1; i<m; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    // 순서쌍 구하기
    combi(-1, orderedTuple);

    // 각 순서쌍에 대해 set 구한 뒤, 비교
    for(int i=0; i<t.size(); i++){
        int x1 = get<0>(t[i]);
        int x2 = get<1>(t[i]);
        int x3 = get<2>(t[i]);

        // A의 순서쌍 구하기
        bool isDuplicated = false;
        s.clear();
        for(int i=0; i<n; i++){
            string str= "";
            str += A[i][x1];
            str += A[i][x2];
            str += A[i][x3];
            s.insert(str);
        }

        for(int i=0; i<n; i++){
            string str= "";
            str += B[i][x1];
            str += B[i][x2];
            str += B[i][x3];

            if(s.find(str) != s.end()){
                isDuplicated = true;
                break;
            }
        }
        if(!isDuplicated)
            ret++;
    }

    cout << ret << "\n";

    return 0;
}
