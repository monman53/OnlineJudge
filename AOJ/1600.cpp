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
// #include <tuple>
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
    while(true){
        int m, nmin, nmax;cin >> m >> nmin >> nmax;
        if(m == 0) break;
        vector<int> p(m);
        for(auto &pp : p) cin >> pp;
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        int ans = 0;
        int n;
        for(int i=nmin-1;i<nmax;i++){
            if(ans <= p[i]-p[i+1]){
                n = i+1;
                ans = p[i]-p[i+1];
            }
        }
        cout << n << endl;
    }
    return 0;
}
