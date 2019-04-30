// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// べき乗
// verified AOJ NTL_1_B
LL mpow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = mpow(a, b/2);
    return aa*aa*(b%2 == 1 ? a : 1);
}

// 素数判定 (エラトステネスのふるい)
#define SIZE 100005
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
vector<pair<long long, int>> factor(long long n) {
    vector<pair<long long, int>> ret;
    for(long long i=2;i*i<=n;i++){
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

int main() {
    std::ios::sync_with_stdio(false);
    LL n;cin >> n;
    initIsPrime();
    auto f = factor(n);
    LL ans = 1;
    for(auto kv : f){
        LL a = 0;
        inc(i, 0, kv.second+1){
            a += mpow(kv.first, i);
        }
        //cout << kv.first << " " << kv.second << endl;
        ans *= a;
    }
    ans -= n;
    //cout << ans << endl;
    if(ans < n){
        cout << "Deficient" << endl;
    }
    if(ans > n){
        cout << "Abundant" << endl;
    }
    if(ans == n){
        cout << "Perfect" << endl;
    }
    return 0;
}
