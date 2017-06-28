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

int H, W;
char mmap[10][10];
char mmap2[10][10];
bool ans=true;

void solve(int ni, int nj){
    mmap2[ni][nj] = '#';
    
    if(ni == H-1 && nj == W-1){
        return;
    }
    if(ni+1 < H && nj+1 < W){
        if(mmap[ni+1][nj] == '#' && mmap[ni][nj+1] == '#'){
            ans=false;
        }
    }
    if(ni+1 < H){
        if(mmap[ni+1][nj] == '#'){
            solve(ni+1, nj);
        }
    }
    if(nj+1 < W){
        if(mmap[ni][nj+1] == '#'){
            solve(ni, nj+1);
        }
    }
    return;
}

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        string s;
        cin >> s;
        for(int j=0;j<W;j++){
            mmap[i][j] = s[j];
            mmap2[i][j] = '.';
        }
    }
    solve(0, 0);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(mmap[i][j] != mmap2[i][j]){
            //kita;
                ans=false;
            }
        }
    }
    if(ans){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
