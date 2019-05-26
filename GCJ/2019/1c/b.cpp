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

int f;

bool solve(int idx) {
    vector<string> vs(120, "");
    string ans = "";

    // 0 119
    map<char, int> mp;
    inc(i, 0, 119){
        cout << i*5+1 << endl;
        char c;cin >> c;
        mp[c]++;
        vs[i].pb(c);
    }
    for(auto kv : mp){
        if(kv.se == 23){
            ans.pb(kv.fi);
            break;
        }
    }

    // 1 23(142)
    mp.clear();
    inc(i, 0, 119){
        if(vs[i] == ans){
            cout << i*5+1+1 << endl;
            char c;cin >> c;
            vs[i].pb(c);
            mp[c]++;
        }
    }
    for(auto kv : mp){
        if(kv.se == 5){
            ans.pb(kv.fi);
            break;
        }
    }

    // 2 5(147)
    mp.clear();
    inc(i, 0, 119){
        if(vs[i] == ans){
            cout << i*5+1+2 << endl;
            char c;cin >> c;
            vs[i].pb(c);
            mp[c]++;
        }
    }
    for(auto kv : mp){
        if(kv.se == 1){
            ans.pb(kv.fi);
            break;
        }
    }

    mp.clear();
    int ok[5] = {0, 0, 0, 0, 0};
    for(auto c : ans){
        ok[c-'A'] = 1;
    }
    inc(i, 0, 5){
        if(ok[i] == 0){
            mp[char('A'+i)] = 0;
        }
    }

    // 3 1(148)
    inc(i, 0, 119){
        if(vs[i] == ans){
            cout << i*5+1+3 << endl;
            char c;cin >> c;
            vs[i].pb(c);
            mp[c]++;
        }
    }
    for(auto kv : mp){
        if(kv.se == 0){
            ans.pb(kv.fi);
            break;
        }
    }

    // last
    mp.clear();
    int ok2[5] = {0, 0, 0, 0, 0};
    for(auto c : ans){
        ok2[c-'A'] = 1;
    }
    inc(i, 0, 5){
        if(ok2[i] == 0){
            ans.pb(char('A'+i));
        }
    }

    cout << ans << endl;
    char c;cin >> c;
    if(c == 'N'){
        return false;
    }
    return true;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;cin >> f;
    inc(i, 0, t){
        if(!solve(i+1)) return 0;
    }
    return 0;
}
