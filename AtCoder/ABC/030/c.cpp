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
    ll x, y;cin >> x >> y;
    vector<ll> a(n), b(m);
    for(auto &aa : a) cin >> aa;
    for(auto &bb : b) cin >> bb;
    int ai = 0, bi = 0;
    ll time = 0;
    int count = 0;
    while(true){
        // a->b
        while(true){
            if(a[ai] < time){
                ai++;
                if(ai == n){
                    cout << count << endl;
                    return 0;
                }
            }else{
                break;
            }
        }
        time = a[ai] + x;

        // b->a
        while(true){
            if(b[bi] < time){
                bi++;
                if(bi == m){
                    cout << count << endl;
                    return 0;
                }
            }else{
                break;
            }
        }
        time = b[bi] + y;

        count++;
    }
    return 0;
}
