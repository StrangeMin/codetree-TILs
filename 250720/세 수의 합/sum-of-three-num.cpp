#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[1000];
unordered_map<int,int> m;
int ret;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        long long diff = (long long)k - arr[i];
        for(int j=i+1; j<n; j++){
            long long diff2 = diff - arr[j];

            ret += m[diff2];
        }
        m[arr[i]]++;
    }

    cout << ret << "\n";

    return 0;
}


// 5 4
// 1 2 1 4 -1

/*
arr[0] = 1
diff =3
arr[1] = 2
diff2 = 1

-- m[1] = 1;
*/