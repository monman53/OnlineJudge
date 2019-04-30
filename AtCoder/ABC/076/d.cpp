
// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> t(n), v(n);
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> vv(200*100+5, 999999);
    vector<int> vvv(200*100+5, 999999);
    //vector<int> ans(200*100+5);

    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=t[i];j++){
            vv[sum+j] = min(vv[sum+j], v[i]);
        }
        for(int j=0;j<t[i];j++){
            vvv[sum+j] = v[i];
        }
        sum += t[i];
    }


    vv[0] = 0;
    vv[sum] = 0;
    for(int i=0;i<=sum;i++){
        for(int j=1;j<sum;j++){
            if(abs(vv[j]-vv[j-1]) <= 1 && abs(vv[j]-vv[j+1]) <= 1) continue;
            vv[j] = min({vv[j], vv[j-1]+1, vv[j+1]+1});
        }
    }

    for(int i=0;i<=sum;i++){
        //cout << i << ":" << vv[i] << endl;
    }

    double ans = 0;

    for(int i=0;i<sum;i++){
        double l = vv[i];
        double r = vv[i+1];
        if(vv[i] == vv[i+1]){
            if(vv[i] == vvv[i]){
                ans += l*1.0;
            }else{
                ans += l*1.0 + 1.0*0.5*0.5;
            }
        }else{
            ans += (l+r)*1.0*0.5;
        }
        //cout << ans << endl;
    }

    printf("%lf\n", ans);

    return 0;
}

