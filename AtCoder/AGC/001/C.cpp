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

struct Node{
    vector<int> to;
};

Node v[2000];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, 0, n){
        int a, b;
        a--;
        b--;
        v[a].to.push_back(b);
        v[b].to.push_back(a);
    }
    int ans = 0;
    rep(i, 0, n){
        stack<pair<int, int> > s;
        s.push(make_pair(i, 0));
        while(!s.empty()){
            pair<int, int> now = s.top();
            s.pop();
            int node = now.first;
            int dist = now.second;
        }
    }
    return 0;
}
