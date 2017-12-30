// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> c(n-1), s(n-1), f(n-1);
    for(int i=0;i<n-1;i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j=i;j<n-1;j++){
            if(ans <= s[j]){
                ans = s[j]+c[j];
            }else{
                int k = (ans-s[j]+f[j]-1)/f[j];
                ans += s[j]+k*f[j]-ans+c[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
