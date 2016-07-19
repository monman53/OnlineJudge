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
    int a[101];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int dp[101][3];
    // 0: rest
    // 1: contest
    // 2: gym
    for(int i=0;i<n;i++){
        dp[i][0] = 10000;
        dp[i][1] = 10000;
        dp[i][2] = 10000;
    }

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;

    if(n==1 && a[0] == 0){
        cout << 1 << endl;
        return 0;
    }

    for(int i=0;i<n-1;i++){
        dp[i+1][0] = min(dp[i+1][0], dp[i][0]+1);
        if(a[i+1] == 1){
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
        }
        if(a[i+1] == 2){
            dp[i+1][2] = min(dp[i+1][2], dp[i][0]);
        }
        if(a[i+1] == 3){
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
            dp[i+1][2] = min(dp[i+1][2], dp[i][0]);
        }
        if(a[i] == 1){
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+1);
            if(a[i+1] == 2 || a[i+1] == 3){
                dp[i+1][2] = min(dp[i+1][2], dp[i][1]);
            }
        }
        if(a[i] == 2){
            dp[i+1][0] = min(dp[i+1][0], dp[i][2]+1);
            if(a[i+1] == 1 || a[i+1] == 3){
                dp[i+1][1] = min(dp[i+1][1], dp[i][2]);
            }
        }
        if(a[i] == 3){
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+1);
            dp[i+1][0] = min(dp[i+1][0], dp[i][2]+1);
            if(a[i+1] == 2 || a[i+1] == 3){
                dp[i+1][2] = min(dp[i+1][2], dp[i][1]);
            }
            if(a[i+1] == 1 || a[i+1] == 3){
                dp[i+1][1] = min(dp[i+1][1], dp[i][2]);
            }
        }
    }

    cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;

    return 0;
}
