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
    int n;
    string s;

    cin >> n >> s;
    bool flag = false;

    if(n==1){
        cout << -1 << endl;
    }

    ull ans = 90000000000;
    ull x[200003];

    for(int i=0;i<n-1;i++){
        cin >> x[i];
    }

    for(int i=0;i<n-1;i++){
        if(s[i] == 'R' && s[i+1] == 'L'){
            flag = true;
            ans = min(ans, (x[i+1]-x[i])/2);
        }
    }

    if(flag){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
