// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)

#define rep(i, s, e)    for (int i = (s); i < (int)(e); i++)
//#define PB(e) push_back(e)
//#define MP(a, b) make_pair(a, b)

// for debug
#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main(){
    ull n, x;
    cin >> n >> x;
    ull a, b, c;
    // pair<int, int> edge[3];
    // edge[0].first = edge[1].first = edge[2].first = 0;
    // edge[0].second = edge[1].second = edge[2].second = n;
    int status = 0;
    ull ans = n;
    a = n - x;
    b = x;
    while(1){
        if(status == 0){
            if(a%b == 0){
                ans += (a/b-1)*2*b + b;
                break;
            }
            ans += (a/b)*2*b;
            a -= (a/b)*b;
            status = 1;
        }else{
            if(b%a == 0){
                ans += (b/a-1)*2*a + a;
                break;
            }
            ans += (b/a)*2*a;
            b -= (b/a)*a;
            status = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
