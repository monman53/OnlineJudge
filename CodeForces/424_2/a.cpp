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

int main() {
    int n;cin >> n;
    vector<int> v(n);
    for(auto &vv : v) cin >> vv;

    if(n == 1){
        cout << "YES" << endl;
        return 0;
    }

    int stat = 0;
    int aa = 0;
    for(int i=0;i<n;i++){
        int a = v[i];
        // cout << a << " " << stat << endl;
        switch(stat){
            case 0:
                if(a > aa){
                    stat = 0;
                }else if(a == aa){
                    stat = 1;
                }else if(a < aa){
                    stat = 2;
                }
                break;
            case 1:
                if(a == aa){
                    stat = 1;
                }else if(a < aa){
                    stat = 2;
                }else{
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 2:
                if(a < aa){
                    stat = 2;
                }else{
                    cout << "NO" << endl;
                    return 0;
                }
                break;
        }
        aa = a;
    }
    cout << "YES" << endl;
    return 0;
}
