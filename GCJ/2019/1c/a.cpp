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

bool ans;
string ans_s;
map<char, char> mp;

void check(int k, vector<string> vs, string s) {
    if(ans == true) return;
    if(s.size() > 500) return;
    int n = vs.size();
    set<char> st;
    inc(i, 0, n){
        int m = vs[i].size();
        st.insert(vs[i][k%m]);
    }
    if(st.size() == 3) return;
    if(st.size() == 1){
        int m = vs[0].size();
        s.pb(mp[vs[0][k%m]]);
        ans_s = s;
        ans = true;
        return;
    }
    if(st.size() == 2){
        char cc[2];
        int i = 0;
        for(auto c : st){
            cc[i] = c;
            i++;
        }

        char c;
        if(mp[cc[0]] == cc[1]){
            c = cc[1];
        }else{
            c = cc[0];
        }

        vector<string> nvs;
        inc(i, 0, n){
            int m = vs[i].size();
            if(vs[i][k%m] == c) nvs.pb(vs[i]);
        }
        string ns = s;
        ns.pb(c);
        check(k+1, nvs, ns);
    }
}

void solve(int idx) {
    int a;cin >> a;
    vector<string> vs(a);
    inc(i, 0, a) cin >> vs[i];
    ans = false;

    check(0, vs, "");

    if(ans){
        cout << "Case #" << idx << ": " << ans_s << endl;
    }else{
        cout << "Case #" << idx << ": " << "IMPOSSIBLE" << endl;
    }
}

int main() {
    mp['R'] = 'P';
    mp['S'] = 'R';
    mp['P'] = 'S';
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
