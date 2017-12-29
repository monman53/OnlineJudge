// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL h, w;cin >> h >> w;
    LL ans = min(h, w);
    if(h%3 == 0 || w%3 == 0) ans = 0;
    for(int i=1;i<w;i++){
        vector<LL> v = {i*h, (h/2)*(w-i), (h-h/2)*(w-i)};
        sort(v.begin(), v.end());
        ans = min(ans, v[2]-v[0]);
    }
    for(int i=1;i<h;i++){
        vector<LL> v = {i*w, (w/2)*(h-i), (w-w/2)*(h-i)};
        sort(v.begin(), v.end());
        ans = min(ans, v[2]-v[0]);
    }
    cout << ans << endl;
    return 0;
}
