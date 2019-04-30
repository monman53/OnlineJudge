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
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
using ll  = long long;
using ull = unsigned long long;
// }}}

void dfs(string s, int l, int m, int r){
    cout << "? " << s+to_string(m) << endl;
    cout << flush;
    char c;cin >> c;
    if(c == 'Y'){
        if(r-l>1){
            dfs(s+to_string(m), 0, 5, 9);
            dfs(s, l, (l+m)/2, m);
            dfs(s, m, (m+r)/2, r);
        }else{
            cout << s+to_string(m) << endl;
            cout << flush;
            exit(0);
        }
        cout << s+to_string(m) << endl;
        cout << flush;
        exit(0);
    }else{
        return;
    }
}

int main() {
    dfs("", 0, 5, 9);
    return 0;
}
