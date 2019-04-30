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
        int d, e;cin >> d >> e;
        if(d == 0) break;
        double ans = 100000;
        for(int x=0;x<=d;x++){
            for(int y=0;y<=d;y++){
                if(x + y == d){
                    ans = min(ans, abs(sqrt(double(x*x+y*y)) - e));
                }
            }
        }
        printf("%0.10lf\n", ans);
    }
    return 0;
}
