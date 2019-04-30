// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
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
#define EQ(a, b) (fabs((a)-(b)) < eps)

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> c;
    for(int i=0;i<n;i++){
        c.push_back(i+1);
    }

    int cd = 0;
    for(int i=0;i<m;i++){
        int d;
        cin >> d;
        for(int j=0;j<n;j++){
            if(c[j] == d){
                c[j] = cd;
                break;
            }
        }
        cd = d;
    }

    for(auto cc : c){
        cout << cc << endl;
    }
    return 0;
}
