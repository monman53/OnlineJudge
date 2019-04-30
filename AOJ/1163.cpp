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
// graph flow {{{
template<class T>
struct GF {
    struct EF {
        int to;
        T cap;
        int rev;
    };

    int n;
    vector<vector<EF>> e;

    GF() {}
    GF(int n) {
        this->n = n;
        e.resize(n);
    }

    void add(int from, int to, T cap) {
        e[from].push_back({to, cap, int(e[to].size())});
        e[to].push_back({from, 0, int(e[from].size()-1)});
    }
};


// 最大流 (Ford-Fulkerson) {{{
// O(FE)
// verified AOJ GRL_6_A
template<class T>
struct MF {
    GF<T> g;
    vector<bool> visited;

    MF() {}
    MF(const GF<T> &g) {
        this->g = g;
        visited.resize(g.n, false);
    };

    T dfs(int v, int t, T f) {
        if(v == t) return f;
        visited[v] = true;
        for(auto &e : g.e[v]){
            if(!visited[e.to] && e.cap > 0){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g.e[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T query(int from, int to) {
        T flow = 0;
        while(true){
            fill(visited.begin(), visited.end(), false);
            T f = dfs(from, to, INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};//}}}
//}}}

int main() {
    while(true){
        int m, n;cin >> m >> n;
        if(m == 0) break;
        GF<int> g(m+n+2);
        vector<int> b(m), r(n);
        for(int i=0;i<m;i++){
            cin >> b[i];
            g.add(0, 2+0+i, 1);
        }
        for(int i=0;i<n;i++){
            cin >> r[i];
            g.add(2+m+i, 1, 1);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(gcd(b[i], r[j]) > 1){
                    g.add(i+0+2, j+m+2, 1);
                }
            }
        }

        MF<int> mf(g);

        cout << mf.query(0, 1) << endl;
    }
    return 0;
}
