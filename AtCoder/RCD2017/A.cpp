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

int H, W, K;
int mmap[50][50];
bool checkc[50][50];
bool check[50][50];

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

vector<vector<pair<int, int> > > ans;

void dfs(int ci, int cj, vector<pair<int, int> > v, int p){
    check[ci][cj] = true;
    v.push_back({ci, cj});
    if(v.size() == K){
        for(int i=0;i<K;i++){
            check[v[i].first][v[i].second] = true;
        }
        ans.push_back(v);
        return;
    }

    int mmax = 0;
    int maxi, maxj;
    for(int i=0;i<4;i++){
        int ni = ci + di[i];
        int nj = cj + dj[i];
        if(ni >= 0 && ni < H && nj >= 0 && nj < W){
            if(mmap[ni][nj] > 0 && !check[ni][nj] && !checkc[ni][nj]){
                if(mmax < mmap[ni][nj]){
                    mmax = mmap[ni][nj];
                    maxi = ni;
                    maxj = nj;
                }
            }
        }
    }
    if(mmax > 0){
        dfs(maxi, maxj, v, p*mmax);
    }
    checkc[ci][cj] = false;
    return;
}

int main(){
    // input
    cin >> H >> W >> K;
    for(int i=0;i<H;i++){
        string s;
        cin >> s;
        for(int j=0;j<W;j++){
            mmap[i][j] = int(s[j] - '0');
        }
    }

    // init
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            check[i][j] = false;
            checkc[i][j] = false;
        }
    }

    //
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(mmap[i][j] > 4 && !check[i][j]){
                vector<pair<int, int> > v;
                dfs(i, j, v, 1);
            }
        }
    }
    
    // output
    cout << int(ans.size()) << endl;
    for(int i=0;i<int(ans.size());i++){
        for(int j=0;j<K;j++){
            cout << (ans[i][j].first+1) << " " << (ans[i][j].second+1) << endl;
        }
    }
    return 0;
}
