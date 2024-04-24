#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N, M;
double ret = 5000;
vector<pair<int,int>> candidate;
pair<int, int> ret1;
pair<int, int> ret2;

double calculateDis(pair<int, int> a, pair<int, int> b) {
    return sqrt( pow((a.first - b.first),2) + pow((a.second - b.second),2));
}

int calculateDisToInt(pair<int, int> a, pair<int, int> b) {
    return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
}

void combi(int start, vector<pair<int, int>> v) {
    if (v.size() == M) {
        double tmp = -1;
        pair<int, int> dot1;
        pair<int, int> dot2;
        
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (i == j) continue;
                if (calculateDis(v[i], v[j]) > tmp) {
                    tmp = calculateDis(v[i], v[j]);
                    dot1 = v[i];
                    dot2 = v[j];
                }
            }
        }

        if (tmp < ret) {
            ret = tmp;
            ret1 = dot1;
            ret2 = dot2;
        }

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
        int y,x;
        cin >> y >> x;
        candidate.push_back({ y,x });
    }
    vector<pair<int,int>> v;
    combi(-1, v);

    cout << calculateDisToInt(ret1,ret2) << "\n";

    return 0;
}