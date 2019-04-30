// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long LL;
// }}}

int n;
string s;
pair<LL, LL> sum[15][15];

// [l, r)
pair<LL, LL> solve(int l, int r){
    if(sum[l][r] != pair<LL, LL>{-1, -1}){
        return sum[l][r];
    }
    pair<LL, LL> ret = {stoll(s.substr(l, r-l)), 1};
    for(int i=1;i<r-l;i++){
        auto a = solve(l+i, r);
        ret.first += stoll(s.substr(l, i))*a.second + a.first;
        ret.second += a.second;
    }
    //cout << l << " " << r << " " << ret << endl;
    return sum[l][r] = ret;
}

int main() {
    cin >> s;
    n = s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            sum[i][j] = {-1, -1};
        }
    }
    printf("%lld\n", solve(0, n).first);
    return 0;
}
