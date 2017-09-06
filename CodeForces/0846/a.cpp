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
    vector<int> v(n);
    for(auto &vv : v) cin >> vv;

    vector<int> k;
    vector<int> sum(n+1);
    sum[0] = 0;
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            sum[i]++;
            sum[i+1] = sum[i];
        }else{
            sum[i+1] = sum[i];
            if(i == 0){
                k.push_back(i);
            }else if(v[i-1] == 0){
                k.push_back(i);
            }
        }
    }

    int m = k.size();

    if(m == 0){
        cout << n << endl;
        return 0;
    }

    int ans = 0;

    for(int i=0;i<m;i++){
        int kk = k[i];
        int count[2] = {0, 0};
        for(int j=kk;j<n;j++){
            count[v[j]%2]++;
        }
        if(count[0] > count[1]){
            ans = max(ans, sum[kk]+count[0]);
        }else{
            ans = max(ans, sum[kk]+count[1]);
        }
    }

    cout << ans << endl;
    return 0;
}
