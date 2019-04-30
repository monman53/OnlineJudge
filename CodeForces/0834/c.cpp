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
#define SIZE 100005

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
            for(int j=i*i;j*j<=SIZE;j+=i){
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

bool solve(int a, int b, int n){
    if(a > b) swap(a, b);
    if(a == 1 && b == 1){
        return true;
    }
    int i;
    bool flag = false;
    for(i=n;i<=a;i++){
        while(a%i == 0 && b%(i*i) == 0){
            a/=i;
            b/=i*i;
            if(a > b) swap(a, b);
            flag = true;
        }
    }
    if(flag) return solve(a, b, i+1);
    return false;
}

int main() {
    initIsPrime();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        cout << (solve(a, b, 2) ? "YES" : "NO") << endl;

        // int g = gcd(a, b);
        // int aa = a/g;
        // int bb = b/g;
        // if(aa*bb% == g){
        //     cout << "YES" << endl;
        // }else{
        //     if(aa == bb){
        //       
        //     }
        //     cout << "NO" << endl;
        // }

        // if((a/g)*(b/g) == g){
        //     cout << "YES" << endl;
        //     continue;
        // }
        //
        //
        // auto aa = factor(a);
        // auto bb = factor(b);
        // if(aa.size() != bb.size()){
        //     cout << "NO" << endl;
        // }else{
        //     int m = aa.size();
        //     bool flag = true;
        //     for(int j=0;j<m;j++){
        //         if(aa[j].first != bb[j].first){
        //             flag = false;
        //             break;
        //         }
        //         int an = aa[j].second;
        //         int bn = bb[j].second;
        //         if((an+bn)%3 != 0){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     cout << (flag ? "YES" : "NO") << endl;
        // }
    }
    return 0;
}
