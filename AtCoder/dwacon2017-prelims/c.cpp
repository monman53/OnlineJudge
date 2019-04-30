// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int cnt[5] = {0, 0, 0, 0, 0};
    inc(i, 0, n){
        int a;cin >> a;
        cnt[a]++;
    }
    cnt[1] = max(0, cnt[1]-cnt[3]);
    cnt[1] = max(0, cnt[1]-cnt[2]%2*2);
    cout << cnt[4] + cnt[3] + (cnt[2]+2-1)/2 + (cnt[1]+4-1)/4 << endl;
    return 0;
}
