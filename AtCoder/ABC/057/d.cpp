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
    int n, a, b;cin >> n >> a >> b;
    vector<LL> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    double mmax = 0;
    for(int i=0;i<a;i++){
        mmax += v[i];
    }
    mmax /= a;
    printf("%.8f\n", mmax);

    LL comb[51][51];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j > i){
                comb[i][j] = 0LL;
            }else if(j == 0 || j == i){
                comb[i][j] = 1LL;
            }else{
                comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
            }
        }
    }
    int l = 0;
    for(l=0;l<n;l++){
        if(v[0] != v[l]) break;
    }
    if(a<=l){
        LL ans = 0;
        for(int i=a;i<=min(b, l);i++){
            ans += comb[l][i];
        }
        printf("%lld\n", ans);
    }else{
        int x = 0;
        int y = 0;
        for(int i=0;i<n;i++){
            if(v[i] == v[a-1]){
                x++;
                if(i<a) y++;
            }
        }
        printf("%lld\n", comb[x][y]);
    }
    return 0;
}
