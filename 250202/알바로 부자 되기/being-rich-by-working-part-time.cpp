#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[1000], e[1000], p[1000];
int dp[1000];
vector<tuple<int,int,int>> v;

int getIdx(int end){
    int left = 0;
    int right = end-1;
    int idx = -1;
    int num = get<0>(v[end]);

    while(left <= right){
        int mid = (left + right) / 2;

        if(get<1>(v[mid]) < num){
            idx = mid;
            left = mid + 1;
        }
        else if(get<1>(v[mid]) >= num){
            right = mid - 1;
        }
        
    }

    return idx;
}

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    if(get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);

    return get<1>(a) < get<1>(b);
}

int getCost(int idx){
    if(idx == -1)
        return 0;
    else
        return dp[idx];
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        v.push_back(make_tuple(s[i],e[i],p[i]));
        
    }

    sort(v.begin(), v.end(), cmp);

    dp[0] = get<2>(v[0]);

    for(int i=1; i<N; i++){
        int idx = getIdx(i);
        dp[i] = max(dp[i-1], getCost(idx) + get<2>(v[i]));
        
    }
    // Write your code here!

    cout << dp[N-1] << "\n";

    return 0;
}

