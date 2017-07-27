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
    string s;cin >> s;s = " "+s;
    vector<vector<int>> sum(n+2, vector<int>(256, 0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<256;j++){
            sum[i][j] = sum[i-1][j];
        }
        sum[i][s[i]]++;
    }

    int var = 0;
    for(int i=0;i<256;i++){
        if(sum[n][i] > 0) var++;
    }

    int l = 1;
    int r = 1;
    int ans = INT_MAX;
    while(r <= n){
        int count = 0;
        for(int i=0;i<256;i++){
            int d = sum[r][i]-sum[l-1][i];
            if(d > 0){
                count++;
            }
        }
        if(count == var){
            ans = min(ans, r-l+1);
            if(l == r){
                l++;
                r++;
            }else{
                l++;
            }
        }else{
            r++;
        }
    }
    cout << ans << endl;

    return 0;
}
