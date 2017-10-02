// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL N;cin >> N;
    for(LL h=1;h<=3500;h++){
        for(LL n=h;n<=3500;n++){
            LL hoge = 4LL*h*n-N*n-N*h;
            if(hoge <= 0) continue;
            if(N*h%hoge != 0) continue;
            LL w = N*h*n/hoge;
            if(4LL*h*n*w == N*(n*w + w*h + h*n)){
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}
