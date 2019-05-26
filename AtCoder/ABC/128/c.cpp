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
    int n, m;cin >> n >> m;
    vector<vector<int>> v(m);
    vector<int> p(m);
    inc(i, 0, m){
        int k;cin >> k;
        inc(j, 0, k){
            int s;cin >> s;s--;
            v[i].pb(s);
        }
    }
    inc(i, 0, m){
        cin >> p[i];
    }

    int ans = 0;
    inc(bit, 0, 1<<n){
        int sum = 0;
        inc(i, 0, m){
            int cnt = 0;
            for(auto s : v[i]){
                if((bit>>s)%2){
                    cnt++;
                }
            }
            if(cnt%2 == p[i]){
                sum++;
            }
        }
        if(sum == m){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
