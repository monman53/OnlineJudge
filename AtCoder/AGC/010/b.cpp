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
    LL n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    LL sum = 0;
    inc(i, 0, n){
        sum += a[i];
    }
    string ans = "YES";
    if(sum%(n*(n+1)/2) != 0){
        ans = "NO";
    }
    LL k = sum/(n*(n+1)/2);
    LL dsum = 0;
    int cnt = 0;
    inc(i, 0, n){
        int d = a[(i+1)%n]-a[i]-k;
        dsum += a[(i+1)%n]-a[i];
        if(d < 0){
            if((-d)%n != 0){
                ans = "NO";
            }else{
                cnt+=(-d)/n;
            }
        }else if(d > 0){
            ans = "NO";
        }
    }
    if(cnt != k) ans = "NO";
    if(dsum != 0) ans = "NO";
    cout << ans << endl;
    return 0;
}
