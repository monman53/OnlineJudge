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
    int t;cin >> t;
    inc(i, 0, t){
        int n;cin >> n;
        bool ok = true;

        vector<int> v[2];
        vector<int> w(n);
        inc(i, 0, n){
            cin >> w[i];
        }
        inc(i, 0, n){
            v[i%2].pb(w[i]);
        }

        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());

        int ans;
        inc(i, 0, n-1){
            if(v[i%2][i/2] > v[(i+1)%2][(i+1)/2]){
                ok = false;
                ans = i;
                break;
            }
        }

        cout << "Case #" << i+1 << ": ";
        if(ok){
            cout << "OK";
        }else{
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}
