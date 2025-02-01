#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[1000];
int x2[1000];
vector<pair<int,int>> v;
int dp[1000];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int binarySearch(int num, int end){
    int ret = -1;
    int first = 0;
    int last = end-1;

    while(first <= last){
        int idx = (first + last) / 2;

        if(v[idx].second < num){
            ret = idx;
            first = idx + 1;
        }
        else if(v[idx].second >= num){
            last = idx - 1;
        }
    }

    return ret;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        v.push_back({x1[i], x2[i]});
    }

    sort(v.begin(), v.end(), cmp);

    dp[0] = 1;

    for(int i=1; i<n; i++){

        int idx = binarySearch(v[i].first, i);

        dp[i] = max(dp[i-1], idx == -1 ? 0 : dp[idx] + 1);
    }

    cout << dp[n-1] << "\n";

    // Write your code here!

    return 0;
}
