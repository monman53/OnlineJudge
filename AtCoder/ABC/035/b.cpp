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
    string s;cin >> s;
    int t;cin >> t;
    int cnt = 0;
    int dx = 0;
    int dy = 0;
    for(auto c : s){
        switch(c){
            case 'L':
                dx--;
                break;
            case 'R':
                dx++;
                break;
            case 'U':
                dy++;
                break;
            case 'D':
                dy--;
                break;
            case '?':
                cnt++;
                break;
        }
    }

    int dst = abs(dx) + abs(dy);
    if(t == 1){
        cout << dst + cnt << endl;
    }else{
        cout << (dst >= cnt ? dst-cnt : (cnt-dst)%2) << endl;
        // if(dst >= cnt){
        //     cout << dst - cnt << endl;
        // }else{
        //     if((cnt-dst)%2 == 0){
        //         cout << 0 << endl;
        //     }else{
        //         cout << 1 << endl;
        //     }
        // }
    }

    return 0;
}
