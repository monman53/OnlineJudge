// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n, m;cin >> n >> m;
    int c[n][m];
    int cnt = 0;
    int u = n, d = 0, l = m, r = 0;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int j=0;j<m;j++){
            c[i][j] = s[j];
            if(c[i][j] == 'B'){
                cnt++;
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    if(cnt == 0){
        cout << 1 << endl;
        return 0;
    }
    int h = max(d-u+1, r-l+1);
    if(h > n || h > m){
        cout << -1 << endl;
        return 0;
    }
    cout << h*h - cnt << endl;
    return 0;
}
