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

string solve() {
    LL n, k, v;
    cin >> n >> k >> v;
    vector<string> s(n);
    inc(i, 0, n) cin >> s[i];
    vector<pair<int, string>> ans;
    for(LL i=0;i<k;i++){
        LL j = (k*(v-1)%n+i)%n;
        ans.pb({j, s[j]});
    }
    sort(ans.begin(), ans.end());
    string res = "";
    for(int i=0;i<k;i++){
        res = res + ans[i].se;
        if(i != k-1){
            res += " ";
        }
    }
    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    for(int i=0;i<t;i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
