// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL n, k, r;cin >> n >> k >> r;
    if(r>(n-k+1)*(n-k)/2){
        cout << "No Luck" << endl;
        return 0;
    }

    vector<LL> ans(n, -1);
    LL left=0, right=n-1;
    LL res = r;

    for(int i=1;i<=n;i++){
        if(res >= n-k-i+1 && res > 0){
            ans[right] = i;
            //cout << res << "hoge" << endl;
            right--;
            res -= n-k-i+1;
        }else if(res > 0){
            //cout << res << endl;
            ans[res+k-1] = i; // TODO
            res = 0;
        }else{
            int kk = 0;
            for(int j=i;j<=n;j++){
                while(ans[kk] != -1){
                    kk++;
                }
                ans[kk] = j;
            }
            break;
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
