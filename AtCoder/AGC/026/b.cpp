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

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

bool solve(LL a, LL b, LL c, LL d) {
    if(a < b){
        return false;
    }else{
        if(d < b){
            return false;
        }else{
            if(c < b){ // C < B <= A, B <= D
                return c >= b-gcd(b, d)+a%gcd(b, d);
            }else{ // B <= C, B <= D
                return true;
            }
        }
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (solve(a, b, c, d) ? "Yes" : "No") << endl;
    }
    return 0;
}
