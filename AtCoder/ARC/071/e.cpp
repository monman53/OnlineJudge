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

string s, t;
int ss[100005];
int tt[100005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    inc(i, 0, n){
        ss[i+1] = ss[i] + (s[i] == 'A' ? 1 : 2);
    }
    inc(i, 0, m){
        tt[i+1] = tt[i] + (t[i] == 'A' ? 1 : 2);
    }

    int q;cin >> q;
    inc(i, 0, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string ans = "YES";
        if((ss[b]-ss[a-1])%3 != (tt[d]-tt[c-1])%3) ans = "NO";
        cout << ans << endl;
    }
    return 0;
}
