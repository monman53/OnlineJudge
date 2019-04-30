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
    int n, c;cin >> n >> c;
    vector<int> a(n);
    inc(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    int ans = 100*1000;
    inc(i, 0, 10){
        inc(j, 0, 10){
            if(i == j) continue;
            int cost = 0;
            inc(k, 0, n){
                if(k%2==0){
                    if(a[k] != i) cost += c;
                }else{
                    if(a[k] != j) cost += c;
                }
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
    return 0;
}
