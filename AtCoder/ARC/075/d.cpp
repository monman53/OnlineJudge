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

ll n, a, b;
vector<ll> h;

bool enagh(ll t) {
    ll count = 0;
    for(auto hh : h){
        if(b*t < hh){
            count += (hh-b*t + a-b - 1LL)/(a-b);
        }
    }
    return count <= t;
}

int main() {
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        ll hh;cin >> hh;
        h.push_back(hh);
    }

    // binary search
    ll l = 0;
    ll r = INF;
    ll m = (l+r)/2;
    while(l!=r){
        if(enagh(m)){
            r = m;
        }else{
            l = m+1;
        }
        m = (l+r)/2;
    }

    cout << m << endl;

    return 0;
}
