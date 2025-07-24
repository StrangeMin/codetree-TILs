#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int N, G;
vector<int> group[250000];
int group_size[250000];
int groupSize[250001];
vector<int> myGroupList[100001]; // N번째 사람이 속한 그룹 배열
unordered_set<int> ret;
int startIndex = -1;
queue<int> q;

void invite(int idx){
    
    for(int i=0; i<groupSize[idx]; i++){
        if(ret.find(group[idx][i]) == ret.end()){
            q.push(group[idx][i]);
            ret.insert(group[idx][i]);
            return;
        }
    }
    
}

int main() {
    cin >> N >> G;

    for (int i = 0; i < G; i++) {
        cin >> group_size[i];
        groupSize[i] = group_size[i];

        for (int j = 0; j < group_size[i]; j++) {
            int n;
            cin >> n;
            group[i].push_back(n);
            myGroupList[group[i][j]].push_back(i);

            if(group[i][0] == 2 && group[i][j] == 1)
                startIndex = i;
        }
    }

    int tmp =1;

    q.push(1);
    ret.insert(1);

    while(q.size()){
        int cur = q.front();
        q.pop();

        for(int i=0 ;i<myGroupList[cur].size(); i++){
            int groupIdx = myGroupList[cur][i];
            group_size[groupIdx]--;

            if(group_size[groupIdx] == 1){
                invite(groupIdx);
            }
        }

    }

    cout << ret.size() << "\n";

    return 0;
}
