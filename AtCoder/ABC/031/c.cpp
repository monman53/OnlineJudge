// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = -1000000;
    for(int i=0;i<n;i++){
        int mmax = -1000000;
        int minj = -1;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            int o = 0;
            int e = 0;
            for(int k=0;k<=abs(i-j);k++){
                int l = min(i, j) + k;
                if(k%2 == 0){
                    o += a[l];
                }else{
                    e += a[l];
                }
            }
            if(e > mmax){
                mmax = e;
                minj = j;
            }
        }
        int o = 0;
        int e = 0;
        for(int k=0;k<=abs(i-minj);k++){
            int l = min(i, minj) + k;
            if(k%2 == 0){
                o += a[l];
            }else{
                e += a[l];
            }
        }
        ans = max(ans, o);
    }
    cout << ans << endl;
    return 0;
}
