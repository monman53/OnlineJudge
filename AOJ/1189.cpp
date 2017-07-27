// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}
// number {{{
#define SIZE 1000010

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
LL comb(int n, int r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

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
vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ret;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            int count = 0;
            while(n%i == 0){
                count++;
                n /= i;
            }
            if(count > 0){
                ret.push_back({i, count});
            }
        }
    }
    if(n != 1){
        ret.push_back({n, 1});
    }
    return ret;
}
//}}}

int m, n;
int h[2000][2000];
PII memo[2000][2000];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

PII dfs(int i, int j) {
    if(memo[i][j] != PII{-1, -1}) return memo[i][j];
    PII ret = {0, 0};
    if(h[i][j] == -1) return memo[i][j] = ret;
    if(isPrime[h[i][j]]){
        ret.second = h[i][j];
    }
    ret = max({ret, dfs(i+1, j-1), dfs(i+1, j), dfs(i+1, j+1)});
    if(isPrime[h[i][j]]){
        ret.first++;
    }
    return memo[i][j] = ret;
}

int main() {
    initIsPrime();
    while(true){
        cin >> m >> n;
        if(m == 0) break;
        for(int i=0;i<2000;i++){
            for(int j=0;j<2000;j++){
                h[i][j] = -1;
                memo[i][j] = {-1, -1};
            }
        }
        int p = 1;
        int dir = 0;
        int l = 1;
        int ci = 1000;
        int cj = 1000;
        int si = 1000;
        int sj = 1000;
        h[ci][cj] = 1;
        while(true){
            for(int i=0;i<2;i++){
                for(int j=0;j<l;j++){
                    p++;
                    if(p > m) goto end;
                    ci += di[dir];
                    cj += dj[dir];
                    if(p == n){
                        si = ci;
                        sj = cj;
                    }
                    h[ci][cj] = p;
                }
                dir = (dir+1)%4;
            }
            l++;
        }
end:

        PII ans = dfs(si, sj);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
