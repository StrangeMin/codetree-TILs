#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
int ret = INT_MAX;
pair<int, int> location[10];
vector<int> candidate;
int sy, sx;
int ey, ex;

void go(int index, int movingDistance, vector<int> v) {
    if (v.size() >= 3) {
        int y = location[v.back()].first;
        int x = location[v.back()].second;
        ret = min(ret, abs(y - ey) + abs(x - ex) + movingDistance);
        return;
    }

    if (index >= candidate.size())
        return;

    int curNum = candidate[index];
    int y = location[curNum].first;
    int x = location[curNum].second;
    int curDistance;
    if (v.size()) {
        curDistance = abs(location[v.back()].first - y) + abs(location[v.back()].second - x);
    }
    else {
        curDistance = abs(y - sy) + abs(x - sx);
    }

    v.push_back(curNum);
    go(index + 1, movingDistance + curDistance, v);
    v.pop_back();
    go(index + 1, movingDistance, v);


}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char num;
            cin >> num;
            if (num == 'S') {
                sy = i;
                sx = j;
            }
            else if (num == 'E') {
                ey = i;
                ex = j;
            }
            else if (num != '.') {
                candidate.push_back(num - '0');
                location[num - '0'] = { i,j };
            }
        }
    }
    sort(candidate.begin(), candidate.end());
    vector<int> v;

    
    go(0, 0, v);
    
    ret = (ret == INT_MAX) ? -1 : ret;

    cout << ret << "\n";

    return 0;
}