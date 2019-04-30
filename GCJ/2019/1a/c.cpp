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

vector<pair<string, string>> ss;

int cnt(int k, set<string> st) {
    if(k == ss.size()){
        return st.size()*2;
    }
    int res = st.size()*2;
    string s1 = ss[k].fi;
    string s2 = ss[k].se;
    int n = s1.size();
    int m = s2.size();
    inc(i, 0, n){
        inc(j, 0, m){
            const string sb1 = s1.substr(i);
            const string sb2 = s2.substr(j);
            if(sb1 == sb2 && st.find(sb1) == st.end()){
                set<string> nst = st;
                nst.insert(sb1);
                res = max(res, cnt(k+1, nst));
            }
        }
    }
    return res;
}

void solve(int idx) {
    int n;cin >> n;
    if(n > 6){
        cout << "Case #" << idx << ": 0" << endl;
    }

    string s[6];
    inc(i, 0, n){
        cin >> s[i];
    }

    vector<int> v;
    inc(i, 0, n) v.pb(i);

    int ans = 0;
    do {
        ss.clear();
        inc(i, 0, n/2){
            ss.pb({s[v[i*2]], s[v[i*2+1]]});
        }
        ans = max(ans, cnt(0, {}));
    }while(next_permutation(v.begin(), v.end()));

    cout << "Case #" << idx << ": " << ans << endl;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
