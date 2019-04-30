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

int solve() {
    int n, l;cin >> n >> l;
    vector<int> c(l);
    int sum = 0;
    inc(i, 0, l){
        cin >> c[i];
        sum += c[i];
    }

    vector<pair<int, int>> v;

    int d = n-sum;

    inc(i, 0, d){
        c.pb(0);
        l++;
    }

    inc(i, 0, l){
        int j = 0;
        for(j=0;j<=d;j++){
            if((c[i]+j)*1000/n%10 >= 5){
                break;
            }
        }
        v.pb({j, i});
    }

    sort(v.begin(), v.end());

    int res = 0;
    
    inc(i, 0, l){
        if(v[i].fi <= d){
            d -= v[i].fi;
            c[v[i].se] += v[i].fi;
            res += c[v[i].se]*100/n + 1;
        }else{
            c[v[i].se] += d;
            d = 0;
            res += c[v[i].se]*100/n;
        }
    }

    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        cout << "Case #" << i+1 << ": " << solve() << endl;;
    }
    return 0;
}
