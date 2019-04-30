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
    int a;cin >> a;
    int k = 1;
    for(int i=1;;i++){
        if(i*(i+1)/2 >= a){
            k = i;
            break;
        }
    }
    string ans = "";
    for(int i=0;i<k;i++){
        ans = ")" + ans + "(";
    }
    int d = k*(k+1)/2 - a;
    swap(ans[k-d], ans[k]);
    cout << ans << endl;
    return 0;
}
