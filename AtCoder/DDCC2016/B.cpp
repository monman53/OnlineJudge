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

double R;
int N, M;

double length(int i){
    if(i < 0 || i > N){
        return 0;
    }

    if(i > N/2){
        i = N - i;
    }
    double r = R - i * (2*R/N);
    return sqrt(R*R - r*r) * 2;
}

bool cutted[1005];

bool cutted_f(int i){
    if(i <= 0 || i >= N){
        return true;
    }
    return cutted[i];
}

int main(){
    cin >> R >> N >> M;
    double ans = 0;

    for(int i=0;i<N+5;i++){
        cutted[i] = false;
    }

    while(1){
        bool flag = true;
        for(int i=1;i<N;i++){
            flag &= cutted[i];
        }
        if(flag){
            break;
        }

        int max_i = 0;
        double max_len = 0;
        for(int i=1;i<N;i++){
            if(!cutted[i]){
                if(max_len <= length(i)){
                    max_i = i;
                    max_len = length(i);
                }
            }
        }

        cutted[max_i] = true;
        ans += max_len;

        int max_bi = -1;
        double max_blen = 0;
        for(int i=M;;i++){
            if(max_i - i <= 0){
                break;
            }
            if(!cutted[max_i - i] && max_blen <= length(max_i - i)){
                max_bi = i;
                max_blen = length(max_i - i);
            }
        }

        int max_ai = -1;
        double max_alen = 0;
        for(int i=M;i<=N;i++){
            if(max_i + i >= N){
                break;
            }
            if(!cutted[max_i + i] && max_alen <= length(max_i + i)){
                max_ai = i;
                max_alen = length(max_i + i);
            }
        }

        

        //print4(max_i, max_bi, max_ai, max_len);
        if(max_ai == -1 && max_bi == -1){
            continue;
        }

        if(max_ai == -1){
            cutted[max_i - max_bi] = true;
            continue;
        }
        if(max_bi == -1){
            cutted[max_i + max_ai] = true;
            continue;
        }

        if(max_blen >= max_alen){
            cutted[max_i - max_bi] = true;
        }else{
            cutted[max_i + max_ai] = true;
        }
    }

    printf("%f\n", ans);

    return 0;
}
