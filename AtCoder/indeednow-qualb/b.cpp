// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s, t;cin >> s >> t;
    if(s.size() != t.size()){
        cout << -1 << endl;
        return 0;
    }
    int n = s.size();
    string ss = s+s;
    dec(i, 1, n+1){
        bool flag = true;
        inc(j, 0, n){
            if(ss[i+j] != t[j]) flag = false;
        }
        if(flag){
            cout << n-i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
