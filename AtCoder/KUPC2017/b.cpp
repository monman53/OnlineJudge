// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}


int main() {
    std::ios::sync_with_stdio(false);
    LL n, s, t;cin >> n >> s >> t;
    if(s > t){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    while(s < t){
        ans++;
        t/=2;
    }
    if(s == t){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
