// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int dp[10000005];

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    while(n > 0){
        for(int i=1;i<=n;i++){
            if(n <= i*(i+1)/2){
                cout << i << endl;
                n -= i;
                break;
            }
        }
    }
    return 0;
}
