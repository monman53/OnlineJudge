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
    int n, z, w;cin >> n >> z >> w;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n == 1){
        cout << abs(a[0] - w) << endl;
        return 0;
    }
    int diff = abs(a[n-1] - a[n-2]);
    int last = a[n-1];
    if(abs(w - last) > diff){
        cout << abs(w - last) << endl;
    }else{
        cout << diff << endl;
    }
    return 0;
}
