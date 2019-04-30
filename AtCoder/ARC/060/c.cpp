// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
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
    ll N, A;cin >> N >> A;
    int size = 50*50*2;
    ll dp[N+1][size];
    for(int i=0;i<size;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<N+1;i++){
        ll x;cin >> x;
        x -= A;
        for(int j=0;j<size;j++){
            dp[i][j] = dp[i-1][j];
        }
        dp[i][50*50 + x]++;
        for(int j=0;j<size;j++){
            if(dp[i-1][j] > 0){
                dp[i][j+x] += dp[i-1][j];
            }
        }
    }
    printf("%lld\n", dp[N][50*50]);
    return 0;
}
