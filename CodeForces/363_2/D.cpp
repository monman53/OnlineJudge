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
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main(){
    int a[200001];
    bool kita[200001];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
        kita[i] = false;
    }
    int loop = 0;
    for(int i=0;i<n;i++){
        if(!kita[i] && a[i] != i){
            int j = i;
            while(a[j] != j){
                kita[j] = true;
                j = a[j];
                if(kita[j]){
                    break;
                }
                if(j == i){
                    loop++;
                    break;
                }
            }
        }else{
            cout << i << endl;
        }
    }

    int id = 0;
    for(int i=0;i<n;i++){
        if(!kita[i]){
            id++;
        }
    }

    print2(loop, id);
    return 0;
}
