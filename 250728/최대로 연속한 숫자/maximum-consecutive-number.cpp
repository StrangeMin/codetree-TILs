#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int nums[100000];
set<int> s;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int ret = 0;
        cin >> nums[i];
        s.insert(nums[i]);  

        for (auto it = s.begin(); it != s.end(); ++it) {
            int curNumber = *it;

            if(it == s.begin()){
                ret = max(ret, curNumber);
            }
            else{
                // 이전 원소까지 구하기
                auto prevIt = prev(it);
                ret = max(ret, (curNumber - *prevIt-1));
            }

            auto nextIt = next(it);

            if(nextIt != s.end()){
                ret = max(ret, (*nextIt - curNumber-1));
            }
            else{
                ret = max(ret, n - curNumber);
            }
        }

        cout << ret << "\n";
    }

    // Please write your code here.

    return 0;
}