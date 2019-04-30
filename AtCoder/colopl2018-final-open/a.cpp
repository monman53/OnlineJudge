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

int main() {
    std::ios::sync_with_stdio(false);
    LL n;cin >> n;
    string s;cin >> s;

    LL c = 0;
    LL cnt = 1;
    LL m = s.size();
    inc(i, 0, m){
        if(s[i] == 'A'){
            c += cnt;
            cnt++;
        }else{
            cnt = 1;
        }
    }

    LL an, bn;
    an = bn = 0;
    inc(i, 0, m){
        if(s[i] == 'A'){
            an++;
        }else{
            break;
        }
    }
    dec(i, 0, m){
        if(s[i] == 'A'){
            bn++;
        }else{
            break;
        }
    }

    LL ans = 0;
    if(an == m){
        inc(i, 0, n){
            ans += c + m*m*i;
        }
    }else{
        ans = c*n + an*bn*(n-1);
    }

    cout << ans << endl;
    return 0;
}
