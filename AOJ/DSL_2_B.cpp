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

// SegmentTree
//  使用方法(RMQ)
//  SegmentTree<int> st(n, INT_MAX, [](int a, int b){return min(a, b);});
//
// depends on
#define ST_MAX_N 100000
//
template <typename T> class SegmentTree{  // {{{
public:
    int n;
    T data[ST_MAX_N*4];
    T init;
    function<T(T, T)> op;
    
    SegmentTree(int n, T init, function<T(T, T)> op){
        this->op = op;
        this->n = 1;
        while(this->n < n){
            this->n *= 2;
        }
        this->init = init;
        for(int i=0;i<this->n*2-1;i++){
            data[i] = init;
        }
    }

    void update(int i, T x){
        i += n-1;
        data[i] += x;
        while(i > 0){
            i = (i-1)/2;
            data[i] = op(data[i*2+1], data[i*2+2]);
        }
    }

    int query(int a, int b){
        if(a > b){
            cout << "SegmentTree: range error!" << endl;
            exit(1);
        }
        return query_r(a, b, 0, 0, n);
    }

    T query_r(int a, int b, int k, int l, int r){
        if(r <= a || b <= l){   // [l, r)が[a, b)の外
            return init;       
        }
        if(a <= l && r <= b){   // [l, r)が[a, b)の中に完全に含まれる
            return data[k];     
        }
        
        T vl = query_r(a, b, k*2+1, l, (l+r)/2);  // 二分探索(左)
        T vr = query_r(a, b, k*2+2, (l+r)/2, r);  // 二分探索(右)

        return op(vl, vr);
    }
};  // }}}

int main(){
    int n, q;
    cin >> n >> q;

    SegmentTree<int> rmq(n, 0, [](int a, int b){return a+b;});

    rep(i, 0, q){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            rmq.update(x-1, y);
        }else{
            cout << rmq.query(x-1, y) << endl;
        }
    }
    return 0;
}
