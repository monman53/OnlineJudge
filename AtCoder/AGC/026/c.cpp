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
    int n;cin >> n;
    string ss;cin >> ss;
    string s = ss.substr(0, n);
    string t = ss.substr(n, n);reverse(t.begin(), t.end());
    map<pair<string, string>, LL> ms, mt;
    inc(k, 0, 1 << n){
        string s1, s2, t1, t2;
        inc(i, 0, n){
            if(k&(1 << i)){
                s1.pb(s[i]);
                t1.pb(t[i]);
            }else{
                s2.pb(s[i]);
                t2.pb(t[i]);
            }
        }
        ms[pair<string, string>(s1, s2)]++;
        mt[pair<string, string>(t1, t2)]++;
    }
    LL ans = 0;
    for(auto kv : ms){
        //if(mt.find(kv.fi) == mt.end()) continue;
        ans += kv.se*mt[kv.fi];
    }
    cout << ans << endl;
    return 0;
}
