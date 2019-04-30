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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<bool> c(n, false);
    for(int i=n;i>=1;i--){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(!c[j] && (j+1)%i == 0){
                sum += a[j];
            }
        }
        if(sum <= 0){
            //cout << "kita" << i << endl;
            for(int j=0;j<n;j++){
                if((j+1)%i == 0){
                    c[j] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!c[i]) ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
