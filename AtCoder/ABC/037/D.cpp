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
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;
typedef unsigned long long ull; // }}}
int h, w;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
int mmap[1000][1000];
int memo[1000][1000];

ull dfs(int ii, int jj){
    ull ret = 0;
    if(memo[ii][jj] != -1){
        return memo[ii][jj];
    }
    rep(i, 4){
        int ni = ii + di[i];
        int nj = jj + dj[i];
        if(ni < h && ni >= 0 && nj < w && nj >= 0){
            if(mmap[ii][jj] < mmap[ni][nj]){
                ret += dfs(ni, nj);
                ret %= 1000000007;
            }
        }
    }
    return memo[ii][jj] = ret;
}

int main(){
    cin >> h >> w;
    rep(i, h){
        rep(j, w){
            cin >> mmap[i][j];
            memo[i][j] = -1;
        }
    }
    ull ans = 0;
    rep(i, h){
        rep(j, w){
            ans += dfs(i, j);
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}
