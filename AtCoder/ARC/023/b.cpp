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

//int a[1000][1000];

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, d;cin >> h >> w >> d;
    int ans = 0;
    inc(i, 0, h){
        inc(j, 0, w){
            int a;cin >> a;
            if((i+j)%2 == d%2 && (i+j) <= d){
                ans = max(ans, a);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
