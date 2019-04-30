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

int x[200], y[200], d[200];
int p, q;

using P = pair<int, int>;

pair<int, int> cross(int i, int j) {
    if(d[i] > d[j]) swap(i, j);
    if(d[i] == 0){
        if(d[j] == 0){
            if(y[i] == y[j]){
                return P{min(x[i]+1, x[j]+1), y[i]};
            }else{
                return min(P{x[i]+1, y[i]}, P{x[j]+1, y[j]});
            }
        }
        if(d[j] == 1){
            if(x[i] < x[j] && y[i] > y[j]){
                return P{x[j], y[i]};
            }else{
                return min(P{x[i]+1, y[i]}, P{x[j], y[j]+1});
            }
        }
        if(d[j] == 2){
            if(x[j]-x[i]>1 && y[i] == y[j]){
                return P{x[i]+1, y[i]};
            }else{
                return min(P{x[i]+1, y[i]}, P{x[j]-1, y[j]});
            }
        }
        if(d[j] == 3){
            if(x[i] < x[j] && y[i] < y[j]){
                return P{x[j], y[i]};
            }else{
                return min(P{x[i]+1, y[i]}, P{x[j], y[j]-1});
            }
        }
    }
    if(d[i] == 1){
        if(d[j] == 1){
            if(x[i] == x[j]){
                return P{x[i], min(y[i]+1, y[j]+1)};
            }else{
                return min(P{x[i], y[i]+1}, P{x[j], y[j]+1});
            }
        }
        if(d[j] == 2){
            if(x[i] < x[j] && y[i] < y[j]){
                return P{x[i], y[j]};
            }else{
                return min(P{x[i], y[i]+1}, P{x[j]-1, y[j]});
            }
        }
        if(d[j] == 3){
            if(x[i] == x[j] && y[i] - y[j] > 1){
                return P{x[i], y[i]+1};
            }else{
                return min(P{x[i], y[i]+1}, P{x[j], y[j]-1});
            }
        }
    }
    if(d[i] == 2){
        if(d[j] == 2){
            if(y[i] == y[j]){
                return P{min(x[i]-1, x[j]-1), y[i]};
            }else{
                return min(P{x[i]-1, y[i]}, P{x[j]-1, y[j]});
            }
        }
        if(d[j] == 3){
            if(x[i] > x[j] && y[i] < y[j]){
                return P{x[j], y[i]};
            }else{
                return min(P{x[i]-1, y[i]}, P{x[j], y[j]-1});
            }
        }
    }
    if(d[i] == 3){
        if(d[j] == 3){
            if(x[i] == y[i]){
                return P{x[i], min(y[i]-1, y[j]-1)};
            }else{
                return min(P{x[i], y[i]-1}, P{x[j], y[j]-1});
            }
        }
    }
}

void solve(int idx) {
    cin >> p >> q;
    inc(i, 0, p){
        char c;
        cin >> x[i] >> y[i] >> c;
        if(c == 'E') d[i] = 0;
        if(c == 'N') d[i] = 1;
        if(c == 'W') d[i] = 2;
        if(c == 'S') d[i] = 3;
    }

    map<pair<int, int>, int> mp;

    inc(i, 0, p){
        inc(j, 0, p){
            mp[cross(i, j)]++;
        }
    }

    vector<pair<int, pair<int, int>>> ans;

    for(auto kv : mp) {
        ans.pb({kv.se, {-kv.fi.fi, -kv.fi.se}});
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    cout << "Case #" << idx << ": " << -ans[0].se.fi << " " << -ans[0].se.se << endl;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
