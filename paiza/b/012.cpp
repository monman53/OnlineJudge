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
    int n;cin >> n;
    inc(i, 0, n){
        string s;cin >> s;
        reverse(s.begin(), s.end());
        inc(k, 0, 10){
            int even = 0;
            int odd = k;
            inc(j, 1, 16){
                int m = s[j]-'0';
                if(j%2==1){
                    m *= 2;
                    if(m >= 10){
                        m = m/10+m%10;
                    }
                    even += m;
                }else{
                    odd += m;
                }
            }
            if((even+odd)%10 == 0){
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}
