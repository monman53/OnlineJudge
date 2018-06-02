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

void solve(int idx) {
    int c;cin >> c;
    vector<int> b(c);
    inc(i, 0, c) cin >> b[i];
    if(b[0] == 0 || b[c-1] == 0){
        //printf("Case #%d: IMPOSSIBLE\n", idx+1);
        cout << "Case #" << idx+1 << ": IMPOSSIBLE" << endl;
        return;
    }

    string s;
    inc(i, 0, c) s.pb('.');

    vector<string> ans;
    vector<int> v(c), r(c);
    inc(i, 0, c) v[i] = i;
    int cnt = 0;
    inc(i, 0, c){
        inc(j, 0, b[i]){
            r[cnt+j] = i;
        }
        cnt += b[i];
    }
    while(true){
        string t = s;
        bool f = true;
        inc(i, 0, c){
            if(r[i] == v[i]){
            }else if(r[i] < v[i]){
                f = false;
                t[v[i]] = '/';
                v[i]--;
            }else{
                f = false;
                t[v[i]] = '\\';
                v[i]++;
            }
        }
        ans.pb(t);
        if(f) break;
    }

    //printf("Case #%d: %d\n", idx+1, (int)ans.size());
    cout << "Case #" << idx+1 << ": " << (int)ans.size() << endl;
    for(auto ss : ans){
        cout << ss << endl;
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i);
    }
    return 0;
}
