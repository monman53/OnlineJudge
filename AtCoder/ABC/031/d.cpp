// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int k, n;
vector<string> ans(10, "");
string s = "";
string t = "";

bool solve(int i, int j) {
    if(i == int(s.size())){
        if(j != int(t.size())) return false;
        //inc(i, 1, k+1){
            //cout << ans[i] << endl;
        //}
        //cout << endl;
        return j == int(t.size());
    }
    int d = s[i]-'0';
    int m = ans[d].size();
    if(m == 0){
        inc(l, 1, 3+1){
            if(j+l > int(t.size())) continue;
            ans[d] = t.substr(j, l);
            if(solve(i+1, j+l)) return true;
        }
        ans[d] = "";
    }else{
        if(j+m > int(t.size())) return false;
        if(t.compare(j, m, ans[d]) == 0){
            return solve(i+1, j+m);
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> k >> n;
    inc(i, 0, n){
        string ss, tt;cin >> ss >> tt;
        s += ss;
        t += tt;
    }
    solve(0, 0);
    inc(i, 1, k+1){
        cout << ans[i] << endl;
    }
    return 0;
}
