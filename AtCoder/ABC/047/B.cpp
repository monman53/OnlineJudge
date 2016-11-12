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

int W, H, N;
bool mmap[200][200];

int main(){
    cin >> W >> H >> N;
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            mmap[x][y] = false;
        }
    }
    
    for(int i=0;i<N;i++){
        int X, Y, A;
        cin >> X >> Y >> A;
        switch(A){
            case 1:
                for(int x=0;x<X;x++){
                    for(int y=0;y<H;y++){
                        mmap[x][y] = true;
                    }
                }
                break;
            case 2:
                for(int x=X;x<W;x++){
                    for(int y=0;y<H;y++){
                        mmap[x][y] = true;
                    }
                }
                break;
            case 3:
                for(int x=0;x<W;x++){
                    for(int y=0;y<Y;y++){
                        mmap[x][y] = true;
                    }
                }
                break;
            case 4:
                for(int x=0;x<W;x++){
                    for(int y=Y;y<H;y++){
                        mmap[x][y] = true;
                    }
                }
                break;
        }
    }

    int ans=0;
    
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            if(!mmap[x][y]) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
