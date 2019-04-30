// math {{{
#define SIZE 200010LL

// べき乗
// verified AOJ NTL_1_B
LL mpow(LL a, LL b) {
    if(b == 0LL) return 1LL;
    LL aa = mpow(a, b/2LL);
    return aa*aa%MOD*(b%2LL == 1LL ? a : 1LL)%MOD;
}

// 階乗と階乗の逆元
// ARC077D
LL fact[SIZE] = {1LL, 1LL};
LL finv[SIZE] = {1LL, 1LL};

void initFact() {
    // fact
    for(LL i=2LL;i<SIZE;i++){
        fact[i] = fact[i-1LL]*i%MOD;
    }

    // finv
    finv[SIZE-1] = mpow(fact[SIZE-1LL], MOD-2LL);
    for(LL i=SIZE-1LL;i>=3LL;i--){
        finv[i-1LL] = finv[i]*i%MOD;
    }
}

// 組み合わせの数
// ARC077D
LL comb(LL n, LL r) {
    if(r > n) return 0LL;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

// 最小公倍数
LL lcm(LL m, LL n) {
    return m/gcd(m, n)*n;
}

// 拡張ユークリッドの互除法
// ax + by = gcd(a, b)
LL extgcd(LL a, LL b, LL &x, LL &y) {
    LL g = a; x = 1; y = 0;
    if(b != 0){
        g = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    }
    return g;
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

// うるう年判定
// ARC002B
bool isUruu(int y) {
    return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}

// 西暦y年のm月は何日あるか
// ARC002B
int month(int y, int m) {
    if(m ==  1) return 31;
    if(m ==  2) return 28 + (isUruu(y) ? 1 : 0);
    if(m ==  3) return 31;
    if(m ==  4) return 30;
    if(m ==  5) return 31;
    if(m ==  6) return 30;
    if(m ==  7) return 31;
    if(m ==  8) return 31;
    if(m ==  9) return 30;
    if(m == 10) return 31;
    if(m == 11) return 30;
    if(m == 12) return 31;
    return 0;
}
//}}}
// !!!(未検証) 連立一次方程式 (Gauss-Jordanの消去法) {{{
// O(N^3)
using VEC = vector<double>;
using MAT = vector<VEC>;

VEC gaussJordan(const MAT& A, const VEC& b) {
    int n = A.size();
    MAT B(n, VEC(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            B[i][j] = A[i][j];
        }
        B[i][n] = b[i];
    }
    
    for(int i=0;i<n;i++){
        int pivot = i;
        for(int j=i;j<n;j++){
            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        }
        swap(B[i], B[pivot]);

        if(abs(B[i][i]) < EPS) return VEC();

        for(int j=i+1;j<=n;j++) B[i][j] /= B[i][i];
        for(int j=0;j<n;j++){
            if(i!=j){
                for(int k=i+1;k<=n;k++){
                    B[j][k] -= B[j][i]*B[i][k];
                }
            }
        }
    }
    VEC x(n);
    for(int i=0;i<n;i++) x[i] = B[i][n];
    return x;
}
//}}}
