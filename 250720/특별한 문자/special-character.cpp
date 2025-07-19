#include <iostream>
#include <string>

using namespace std;

string str;
pair<int,int> arr[26];

int findIdx(){
    int idx = str.size();
    int retIdx = -1;
    for(int i=0; i<26; i++){
        if(arr[i].first == 1 && arr[i].second < idx){
            idx = arr[i].second;
            retIdx = i;
        }
    }

    return retIdx;
}

int main() {
    cin >> str;

    for(int i=0; i<str.size(); i++){
        arr[str[i]-97] = {arr[str[i]-97].first + 1, i};
    }

    int idx = findIdx();

    if(idx == -1)
        cout << "None" << "\n";
    else
        cout << (char)(idx+97) << "\n";

    return 0;
}
