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

#define SIZE 200010

// べき乗
// verified AOJ NTL_1_B
LL pow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = pow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

// 階乗と階乗の逆元
// ARC077D
LL fact[SIZE] = {1, 1};
LL finv[SIZE] = {1, 1};

void initFact() {
    // fact
    for(LL i=2;i<SIZE;i++){
        fact[i] = fact[i-1]*i%MOD;
    }

    // finv
    finv[SIZE-1] = pow(fact[SIZE-1], MOD-2);
    for(LL i=SIZE-1;i>=3;i--){
        finv[i-1] = finv[i]*i%MOD;
    }
}

// 組み合わせの数
// ARC077D
LL comb(LL n, LL r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

pair<pair<bool, bool>, pair<LL, LL>> solve(LL a, LL b, LL c) {
    // -b+-sqrt() / 2a
    LL d = b*b-4*a*c;
    if(d < 0){
        return {{false, false}, {0, 0}};
    }
    LL ok = 0;
    LL ng = d;
    if(d == 1){
        ok = 1;
    }
    while(ng-ok>1){
        LL m = (ok+ng)/2;
        if(m*m > d){
            ng = m;
        }else{
            ok = m;
        }
    }

    pair<pair<bool, bool>, pair<LL, LL>> res;
    res = {{false, false}, {0, 0}};

    if(ok*ok != d){
        return res;
    }

    if((-b+ok)%(2LL*a) == 0 && (-b+ok)/(2LL*a) >= 0){
        res.fi.fi = true;
        res.se.fi = (-b+ok)/(2LL*a);
    }

    if((-b-ok)%(2LL*a) == 0 && (-b-ok)/(2LL*a) >= 0){
        res.fi.se = true;
        res.se.se = (-b-ok)/(2LL*a);
    }

    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    initFact();
    int q;cin >> q;
    inc(i, 0, q){
        LL n, k;cin >> n >> k;
        LL qans = 0LL;
        LL m = n/2LL;
        if(n%2LL == 0LL){
            auto ans = solve(-2LL, 2LL*m, -k);
            //cout << ans.se.fi << " " << ans.se.se << endl;
            if(ans.fi.fi && ans.fi.se){
                LL x = ans.se.fi;
                LL y = ans.se.se; 
                if(x != y){
                    qans += (comb(m, x)*2LL%MOD);
                }else{
                    qans += comb(m, x);
                }
            }else if(ans.fi.fi){
                LL x = ans.se.fi;
                qans += comb(m, x);
            }else if(ans.fi.se){
                LL y = ans.se.se;
                qans += comb(m, y);
            }
        }else{
            // 0
            auto ans = solve(-2LL, 2LL*m+1LL, -k);
            //cout << ":0:" << ans.fi.fi << ans.fi.se << endl;
            if(ans.fi.fi && ans.fi.se){
                LL x = ans.se.fi;
                LL y = ans.se.se; 
                if(x != y){
                    qans += (comb(m, x)*2LL%MOD);
                }else{
                    qans += comb(m, x);
                }
            }else if(ans.fi.fi){
                LL x = ans.se.fi;
                MODA(qans, comb(m, x));
            }else if(ans.fi.se){
                LL y = ans.se.se;
                MODA(qans, comb(m, y));
            }

            // 1
            ans = solve(-2LL, 2LL*m-1LL, m-k);
            //cout << ":0:" << ans.fi.fi << ans.fi.se << endl;
            if(ans.fi.fi && ans.fi.se){
                LL x = ans.se.fi;
                LL y = ans.se.se; 
                if(x != y){
                    MODA(qans, (comb(m, x)*2LL%MOD));
                }else{
                    MODA(qans, comb(m, x));
                }
            }else if(ans.fi.fi){
                LL x = ans.se.fi;
                MODA(qans, comb(m, x));
            }else if(ans.fi.se){
                LL y = ans.se.se;
                MODA(qans, comb(m, y));
            }
        }
        cout << qans << endl;
    }
    return 0;
}
