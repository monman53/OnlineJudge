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
    int l, h;cin >> l >> h;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(a < l){
            cout << l-a << endl;
        }else if(h < a){
            cout << -1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
