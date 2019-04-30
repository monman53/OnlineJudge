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
    int n, c;cin >> n >> c;
    vector<int> l(n);
    for(int i=0;i<n;i++) cin >> l[i];
    sort(l.begin(), l.end());
    int ll = 0;
    int rr = n-1;
    int ans = 0;
    while(ll <= rr){
        if(ll == rr){
            ans++;
            ll++;
            rr--;
        }else{
            if(l[ll]+l[rr]+1 <= c){
                ans++;
                ll++;
                rr--;
            }else{
                ans++;
                rr--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
