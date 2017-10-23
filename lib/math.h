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

// 最小公倍数
LL lcm(LL m, LL n) {
    return m/gcd(m, n)*n;
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
