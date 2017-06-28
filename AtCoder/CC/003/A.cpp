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

#define N 50

char mmap[N][N];
char buff[N][N];
char after[N][N];
bool check[N][N];

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

void change_after(int cj){
    for(int i=0;i<N;i++){
        after[i][cj] = ' ';
    }
    for(int i=N-1, k=N-1;i>=0;i--){
        switch(buff[i][cj]){
            case 'x':
            case 'o':
            case '+':
                after[k][cj] = buff[i][cj];
                k--;
                break;
            case '-':
                after[i][cj] = '-';
                k = i-1;
                break;
            default:
                break;
        }
    }
}

void init_after(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            after[i][j] = ' ';
        }
    }
    for(int j=0;j<N;j++){
        change_after(j);
    }
}

// void show_after(){
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             cout << after[i][j];
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void init_check(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            check[i][j] = false;
        }
    }
}

int dfs(int ci, int cj, char c){
    int ret = 1;
    check[ci][cj] = true;

    for(int d=0;d<4;d++){
        int ni = ci + di[d];
        int nj = cj + dj[d];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N){
            if(!check[ni][nj] && after[ni][nj] == c){
                ret += dfs(ni, nj, c);
            }
        }
    }
    return ret;
}

int calc(int j){
    int omax = 0;
    int xmax = 0;
    init_check();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!check[i][j]){
                if(after[i][j] == 'o'){
                    omax = max(omax, dfs(i, j, 'o'));
                }
                if(after[i][j] == 'x'){
                    xmax = max(xmax, dfs(i, j, 'x'));
                }
            }
        }
    }
    return omax + xmax;
}

int calc_all(){
    int pmax = 0;
    for(int j=0;j<N;j++){
        pmax = max(pmax, calc(j));
    }
    return pmax;
}

int point;

void change(int i, int j, char from, char to){
    int npoint;
    buff[i][j] = to;
    change_after(j);
    if(point < (npoint = calc(j))){
        point = npoint;
    }else{
        buff[i][j] = from;
        change_after(j);
    }
}

int main(){
    // input
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            buff[i][j] = mmap[i][j] = s[j];
        }
    }

    // main
    init_after();
    init_check();
    
    // show_after();
    // cout << calc_all() << endl;

    point = calc_all();

    for(int m=0;m<7;m++){
        for(int n=0;n<18;n++){
            for(int i=N-1;i>=0;i--){
                for(int j=0;j<N;j++){
                    if(buff[i][j] == '.'){
                        change(i, j, '.', '+');
                    }
                    if(buff[i][j] == '+'){
                        change(i, j, '+', '.');
                    }
                }
            }
        }
        for(int n=0;n<18;n++){
            for(int i=N-1;i>=0;i--){
                for(int j=0;j<N;j++){
                    if(buff[i][j] == '.'){
                        change(i, j, '.', '-');
                    }
                    if(buff[i][j] == '+'){
                        change(i, j, '+', '-');
                    }
                }
            }
        }
    }
    


    // show_after();
    // cout << calc_all() << endl;

    // output
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << buff[i][j];
        }
        cout << endl;
    }

    return 0;
}
