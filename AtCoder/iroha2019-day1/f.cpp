// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    vector<int> ans;
    if(k == 1){
        cout << n << endl;
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            ans.pb(i);
            n /= i;
            if(ans.size() == k-1){
                ans.pb(n);
                break;
            }
        }
        if(ans.size() == k) break;
    }
    if(ans.size() != k){
        cout << -1 << endl;
        return 0;
    }
    inc(i, 0, k){
        cout << ans[i];
        if(i < k-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
