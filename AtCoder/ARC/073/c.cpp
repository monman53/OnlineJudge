// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, T;cin >> n >> T;
    LL ans = 0LL;
    vector<LL> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=1;i<n;i++){
        if(t[i]-t[i-1] < T){
            ans += t[i]-t[i-1];
        }else{
            ans += T;
        }
    }
    ans += T;
    cout << ans << endl;
    return 0;
}
