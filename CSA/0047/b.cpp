// header {{{
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
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int sum[100005];
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+i;
    }
    int l = 1;
    int r = 2;
    while(l<r && r<=n){
        int ssum = sum[r]-sum[l-1];
        if(ssum == n){
            cout << l << " " << r << endl;
            return 0;
        }else if(ssum < n){
            r++;
        }else{
            l++;
        }
    }
    cout << -1 << endl;
    return 0;
}
