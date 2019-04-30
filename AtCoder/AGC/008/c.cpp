// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL a[7];
    inc(i, 0, 7) cin >> a[i];
    LL ans = a[1];
    if(a[0] > 0 && a[3] > 0 && a[4] > 0){
        ans += max(a[0]/2*2+a[3]/2*2+a[4]/2*2, 
                   (a[0]-1)/2*2+(a[3]-1)/2*2+(a[4]-1)/2*2 + 3);
    }else{
        ans += a[0]/2*2+a[3]/2*2+a[4]/2*2;
    }
    cout << ans << endl;
    return 0;
}
