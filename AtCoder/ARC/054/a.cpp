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

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    double l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;
    vector<double> ans;
    if(d > s){
        ans.push_back((d-s)/(x+y));
    }else{
        ans.push_back((l-s+d)/(x+y));
    }
    if(y > x){
        if(d > s){
            ans.push_back((l-d+s)/(y-x));
        }else{
            ans.push_back((s-d)/(y-x));
        }
    }

    printf("%.10lf\n", *min_element(ans.begin(), ans.end()));
    return 0;
}
