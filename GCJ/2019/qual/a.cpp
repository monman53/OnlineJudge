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

string remove0(string s) {
    string res = "";
    int n = s.size();
    bool ok = false;
    inc(i, 0, n){
        if(s[i] == '0' && !ok) continue;
        if(s[i] != '0') ok = true;
        res.pb(s[i]);
    }
    return res;
}

void solve(int idx) {
    string s;
    cin >> s;
    string a = "";
    string b = "";
    int n = s.size();
    inc(i, 0, n){
        if(s[i] == '4'){
            a.pb('2');
            b.pb('2');
        }else{
            a.pb('0');
            b.pb(s[i]);
        }
    }
    a = remove0(a);
    b = remove0(b);
    cout << "Case #" << idx << ": " << a << " " << b << endl; 
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        solve(i+1);
    }
    return 0;
}
