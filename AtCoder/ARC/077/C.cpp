// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <list>
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

#define eps (1e-10)
#define equals(a, b) (fabs((a)-(b)) < eps)

#define rep(i, s, e)    for (int i = (s); i < (int)(e); i++)
//#define pb(e) push_back(e)
//#define mp(a, b) make_pair(a, b)

// for debug
#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main() {
    int n;
    vector<int> a;
    list<int> b;

    cin >> n;

    for(int i=0;i<n;i++){
        int aa;
        cin >> aa;
        a.push_back(aa);
    }

    for(int i=0;i<n;i++){
        if(i%2 == 0){
            b.push_back(a[i]);
        }else{
            b.push_front(a[i]);
        }
    }


    if(n%2 != 0){
        reverse(b.begin(), b.end());
    }

    bool flag = true;
    for(auto bb : b){
        if(!flag){
            cout << " ";
        }
        flag = false;
        cout << bb;
    }

    cout << endl;

    return 0;
}
