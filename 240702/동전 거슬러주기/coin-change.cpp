#include <iostream>


using namespace std;

int N,M;

int dp[10001];
int coin[101];

int main() {
    
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int amount;
        cin >> amount;
        coin[amount]++;
    }

    for(int origin=1; origin<=M; origin++){
        for(int exchange = origin; exchange>=1; exchange--){
            if(coin[exchange]){
                if(origin % exchange == 0)
                    dp[origin] = origin / exchange;
                if(dp[origin%exchange]){
                    dp[origin] = dp[origin%exchange] + origin/exchange;
                    break;
                }
            }
        }
    }

    cout << ( dp[M] !=0 ? dp[M] : -1 ) << "\n";

    return 0;
}