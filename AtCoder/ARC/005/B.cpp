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
    int cj, ci;
    string w;
    char mmap[9][9];

    cin >> cj >> ci;
    cin >> w;
    cj--;
    ci--;

    for(int i=0;i<9;i++){
        string s;
        cin >> s;
        for(int j=0;j<9;j++){
            mmap[i][j] = s[j];
        }
    }

    map<string, int> di, dj;

    di["R"] = 0;
    di["L"] = 0;
    di["U"] = -1;
    di["D"] = 1;
    di["RU"] = -1;
    di["RD"] = 1;
    di["LU"] = -1;
    di["LD"] = 1;

    dj["R"] = 1;
    dj["L"] = -1;
    dj["U"] = 0;
    dj["D"] = 0;
    dj["RU"] = 1;
    dj["RD"] = 1;
    dj["LU"] = -1;
    dj["LD"] = -1;

    for(int i=0;i<4;i++){
        int ni = ci + i*di[w];
        int nj = cj + i*dj[w];
        if(ni < 0){
            ni = -ni;
        }
        if(ni >= 9){
            ni = 16 - ni;
        }
        if(nj < 0){
            nj = -nj;
        }
        if(nj >= 9){
            nj = 16 - nj;
        }
        cout << mmap[ni][nj];
    }
    cout << endl;

    return 0;
}
