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

LL score(string s) {
    LL res = 0;
    LL p = 1;
    for(auto c : s){
        if(c == 'C'){
            p *= 2;
        }
        if(c == 'S'){
            res += p;
        }
    }
    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        LL d;cin >> d;
        string s;cin >> s;
        int n = s.size();
        bool flag = true;
        LL ans = 0;
        while(score(s) > d && flag){
            dec(i, 1, n){
                if(s[i-1] == 'C' && s[i] == 'S'){
                    swap(s[i-1], s[i]);
                    ans++;
                    break;
                }
                if(i == 1){
                    flag = false;
                }
            }
        }
        cout << "Case #" << i+1 << ": ";
        if(flag){
            cout << ans;
        }else{
            cout << "IMPOSSIBLE";
        }
        cout << endl;
        //cout << "Case #" << i+1 << ": 0" << endl;
    }
    return 0;
}
