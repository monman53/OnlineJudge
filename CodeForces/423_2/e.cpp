// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}
// Segment tree // {{{
// verified AOJ DSL_2_{A,B}
template <typename T>
struct SGT {
    vector<T> dat;
    int n;
    T init;
    SGT(int n, T init) {
        this->n     = n;
        this->init  = init;
        dat = vector<T>(4*n, init);
    }
    T update(int i, T x, int k, int l, int r) {
        if(i < l || r <= i) return dat[k];
        if(l+1 == r) return dat[k] = x;
        T vl = update(i, x, k*2+1, l, (l+r)/2);
        T vr = update(i, x, k*2+2, (l+r)/2, r);
        return dat[k] = vl + vr;
    }
    // [a, b)の所望の値．[l, r)はノードkに対応する区間．
    T find(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return dat[k];

        T vl = find(a, b, k*2+1, l, (l+r)/2);
        T vr = find(a, b, k*2+2, (l+r)/2, r);
        return vl + vr;
    }
    // interfaces
    T update(int i, T x) {
        update(i, x, 0, 0, n);
    }
    T find(int a, int b) {
        return find(a, b, 0, 0, n);
    }
};//}}}

int main() {
    string s;cin >> s;
    int q;cin >> q;
    int n = s.size();
    // map<char, int> m;
    // m['A'] = 0;
    // m['T'] = 1;
    // m['G'] = 2;
    // m['C'] = 3;
    // SGT<int> A(n+5, 0);
    // SGT<int> T(n+5, 0);
    // SGT<int> G(n+5, 0);
    // SGT<int> C(n+5, 0);
    // for(int i=0;i<n;i++){
    //     switch(s[i]){
    //         case 'A':
    //             A.update(i, 1);
    //             break;
    //         case 'T':
    //             T.update(i, 1);
    //             break;
    //         case 'G':
    //             G.update(i, 1);
    //             break;
    //         case 'C':
    //             C.update(i, 1);
    //             break;
    //     }
    // }

    for(int i=0;i<q;i++){
        int qq;cin >> qq;
        if(qq == 1){
            int x;char c;cin >> x >> c;
            x--;
            s[x] = c;
            // A.update(x, 0);
            // T.update(x, 0);
            // G.update(x, 0);
            // C.update(x, 0);
            // switch(c){
            //     case 'A':
            //         A.update(x, 1);
            //         break;
            //     case 'T':
            //         T.update(x, 1);
            //         break;
            //     case 'G':
            //         G.update(x, 1);
            //         break;
            //     case 'C':
            //         C.update(x, 1);
            //         break;
            // }
        }else{
            int l, r;string e;cin >> l >> r >> e;
            l--;r--;
            int count = 0;
            int m = e.size();
            for(int j=0;j<r-l+1;j++){
                // cout << j << endl;
                if(s[l+j] == e[j%m]) count++;
            }
            cout << count << endl;
            // int move = max(0, r-l+1-m);
            // cout << "move: " <<  move << endl;
            // for(int j=0;j<min(r-l+1, m);j++){
            //     char c = e[j];
            //     switch(c){
            //         case 'A':
            //             count += A.find(l+j, l+j+move+1);
            //             break;
            //         case 'T':
            //             count += T.find(l+j, l+j+move+1);
            //             break;
            //         case 'G':
            //             count += G.find(l+j, l+j+move+1);
            //             break;
            //         case 'C':
            //             count += C.find(l+j, l+j+move+1);
            //             break;
            //     }
            //     cout << c << " " << count << endl;
            // }
        }
        // cout << A.find(0, n) << " " << T.find(0, n) << " " << G.find(0, n) << " " << C.find(0, n) << endl;
    }

    return 0;
}
