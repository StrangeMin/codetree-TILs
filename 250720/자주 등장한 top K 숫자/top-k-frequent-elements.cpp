#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];
int cnt;
map<int,int> m;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first)
        return a.second > b.second;
    
    return a.first > b.first;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    
        m[arr[i]]++;
    }

    vector<pair<int,int>> v;
    for(auto it : m){
        cnt = max(cnt, it.second);
        v.push_back({it.second, it.first}); // 등장횟수, 값
    }

    sort(v.begin(), v.end(), cmp);

    for(auto it : v){
        if(it.first == cnt)
            cout << it.second << " ";
    }
    cout << "\n";

    return 0;
}
