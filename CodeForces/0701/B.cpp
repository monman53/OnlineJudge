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
    ull n, m;

    bool ii[100005];
    bool jj[100005];
    int counti = 0;
    int countj = 0;

    cin >> n >> m;

    rep(i, 0, n){
        ii[i] = false;
        jj[i] = false;
    }

    ull ans = n*n;

    rep(k, 0, m){
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        if(!ii[i] && !jj[j]){
            ans += 1;
        }

        if(!ii[i]){
            ans -= n - countj;
        }

        if(!jj[j]){
            ans -= n - counti;
        }

        cout << ans << " ";

        if(!ii[i]){
            counti++;
            ii[i] = true;
        }
        if(!jj[j]){
            countj++;
            jj[j] = true;
        }
    }

    cout << endl;
    
    return 0;
}
