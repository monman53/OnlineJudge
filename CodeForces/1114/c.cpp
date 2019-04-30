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

using LL  = unsigned long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

const int SIZE = 5000000;

// 素数判定 (エラトステネスのふるい)
bool isPrime[SIZE];
void initIsPrime() {
    for(int i=0;i<SIZE;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=SIZE;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=SIZE;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

// 素因数分解
// verified AOJ NTL_1_A
// ARC026B
vector<pair<LL, LL>> factor(LL n) {
    vector<pair<LL, LL>> ret;
    for(LL i=2ULL;i*i<=n;i++){
        if(isPrime[i]){
            LL count = 0ULL;
            while(n%i == 0ULL){
                count++;
                n /= i;
            }
            if(count > 0ULL){
                ret.push_back({i, count});
            }
        }
    }
    if(n != 1ULL){
        ret.push_back({n, 1ULL});
    }
    return ret;
}

LL cnt(LL n, LL p) {
    LL res = 0ULL;
    LL d = p;
    //cout << endl;
    while(n/d > 0){
        //cout << n << " " << d << " " << p << endl;
        res += n/d;
        if(n/d < p) break;
        d *= p;
    }
    return res;
}

int main() {
    LL n, b;
    cin >> n >> b;
    initIsPrime();
    auto fac = factor(b);
    vector<LL> ans;
    for(auto kv : fac){
        LL p = kv.fi;
        LL m = kv.se;
        //cout << "p:" << p << " c:" << c << " m:" << m << endl;
        ans.pb(cnt(n, p)/m);
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
    return 0;
}
