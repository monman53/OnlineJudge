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
typedef unsigned long long ull; // }}}ull ans[100005][100005];


int main(){
    int ans[2][100005];
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    rep(i, 0, w+1){
        ans[0][i] = 0;
    }
    ans[0][1] = 1;
    ans[1][0] = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(!(i>=h-a+1 && j<=b)){
                ans[i%2][j] = (ans[i%2][j-1] + ans[1-i%2][j])%1000000007;
            }else{
                ans[i%2][j] = 0;
            }
        }
    }

    cout << ans[h%2][w] << endl;
}
