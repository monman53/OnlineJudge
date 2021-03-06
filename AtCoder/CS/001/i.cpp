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

int main() {
    int n;cin >> n;
    vector<int> a(n);
    vector<int> sum(n+1);
    for(auto &aa : a) cin >> aa;
    sum[0] = 0;
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i]+a[i];
    }
    int l = 0;
    int r = 1;
    int count = 0;
    while(true){
        int nn = sum[r] - sum[l];
        if(nn == n){
            count++;
            r++;
            l++;
            if(r > n) break;
        }
        if(nn > n){
            if(l == r-1){
                l++;
                r++;
                if(r > n) break;
            }else{
                l++;
            }
        }
        if(nn < n){
            r++;
            if(r > n) break;
        }
    }
    cout << count << endl;
    return 0;
}
