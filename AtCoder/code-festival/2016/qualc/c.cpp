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
    vector<LL> t(n), a(n), th(n), ah(n);
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++) cin >> a[i];
    LL ans = 1;
    for(int i=0;i<n;i++){
        th[i] = t[i];
        if(i > 0){
            if(t[i-1] == t[i]) th[i] = 0;
        }
        ah[i] = a[i];
        if(i < n-1){
            if(a[i] == a[i+1]) ah[i] = 0;
        }

        //cout << th[i] << " " << ah[i] << endl;

        if(th[i] == 0 && ah[i] == 0){
            ans *= min(t[i], a[i]);
            ans %= MOD;
        }
        if(th[i] == 0 && ah[i] != 0){
            if(t[i] < ah[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(th[i] != 0 && ah[i] == 0){
            if(a[i] < th[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        if(th[i] != 0 && ah[i] != 0){
            if(th[i] != ah[i]){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
