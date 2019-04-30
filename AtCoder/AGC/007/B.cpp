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

ll N;

int main(){
    cin >> N;
    ll p[30000];
    ll ans[30000];
    for(ll i=0;i<N;i++){
        ans[i] = (N-i)*30000;
    }

    for(ll i=0;i<N;i++){
        cin >> p[i];
        cout << (i+1)*30000;
        ans[p[i]-1] += i+1;
        if(i==N-1){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
    for(ll i=0;i<N;i++){
        cout << ans[i];
        if(i==N-1){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
    return 0;
}
