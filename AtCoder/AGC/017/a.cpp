// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    ll n, p;cin >> n >> p;
    vector<ll> a(n);
    for(auto &aa : a){
        cin >> aa;
        aa %= 2;
    }
    ll dp[n+1][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i=1;i<n+1;i++){
        if(a[i-1] == 0){
            dp[i][0] = dp[i-1][0]*2;
            dp[i][1] = dp[i-1][1]*2;
        }else{
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][1] + dp[i-1][0];
        }
    }
    printf("%lld\n", dp[n][p]);
    return 0;
}
