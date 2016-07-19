// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
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

int n, m;
int bombs_org = 0;
int bombs;
char map_org[2000][2000];
int sumi[2000], sumj[2000];
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int sum = 0;
        for(int j=0;j<m;j++){
            map_org[i][j] = s[j];
            if(s[j] == '*'){
                bombs_org++;
                sum++;
            }
        }
        sumi[i] = sum;
    }

    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(map_org[j][i] == '*'){
                sum++;
            }
        }
        sumj[i] = sum;
    }
    
    bool flag = false;
    int ansi, ansj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bombs = sumi[i] + sumj[j];

            if(map_org[i][j]=='*'){
                bombs--;
            }

            if(bombs == bombs_org){
                flag = true;
                ansi = i;
                ansj = j;
            }
        }
    }

    if(flag){
        cout << "YES" << endl;
        cout << ansi+1 << " " << ansj+1 << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
