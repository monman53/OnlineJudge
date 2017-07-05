// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int mmin = 200;
    for(int i=0;i<n;i++){
        int s;cin >> s;
        sum += s;
        if(s%10 != 0){
            mmin = min(mmin, s);
        }
    }

    if(sum%10 != 0){
        cout << sum << endl;
    }else{
        if(mmin != 200){
            cout << sum - mmin << endl;
        }else{
            cout << 0 << endl;
        }
    }

    return 0;
}
