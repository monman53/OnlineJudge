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
    LL n, h;cin >> n >> h;
    vector<LL> a(n), b(n);
    inc(i, 0, n){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());reverse(a.begin(), a.end());
    sort(b.begin(), b.end());reverse(b.begin(), b.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(h > 0){
        if(a[i] < b[j]){
            h -= b[j];
            ans++;
            j++;
        }else{
            ans += (h+a[i]-1)/a[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
