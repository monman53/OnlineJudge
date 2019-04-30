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

struct Food{
    int i, j;
    int F, D;
};

int N;
int H, W, K, sr, sc;
char mmap[50][50];
bool scheck[50][50];

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

string route(int si, int sj, int gi, int gj){
    // print4(si, sj, gi, gj);
    string ret = "";
    bool check[50][50];
    pair<int, int> from[50][50];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            check[i][j] = false;
        }
    }
    queue<pair<int, int> > q;
    q.push({si, sj});
    from[si][sj] = {si, sj};
    check[si][sj] = true;
    while(!q.empty()){
        pair<int, int> cq = q.front();
        int ci = cq.first;
        int cj = cq.second;
        q.pop();
        // print2(ci, cj);
        if(ci == gi && cj == gj){
            while(!(ci == si && cj == sj)){
                int fi = from[ci][cj].first;
                int fj = from[ci][cj].second;
                scheck[fi][fj] = true;

                if(ci-fi>0){
                    ret = ret + "D";
                }
                if(ci-fi<0){
                    ret = ret + "U";
                }
                if(cj-fj>0){
                    ret = ret + "R";
                }
                if(cj-fj<0){
                    ret = ret + "L";
                }

                ci = fi;
                cj = fj;
            }
            break;
        }
        for(int i=0;i<4;i++){
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                if(!check[ni][nj] && mmap[ni][nj] == '.'){
                    check[ni][nj] = true;
                    from[ni][nj] = {ci, cj};
                    q.push({ni, nj});
                }
            }
        }
    }
    return ret;
}

int main(){
    vector<pair<double, pair<int, int> > > food;
    // input
    cin >> H >> W >> K >> sr >> sc;
    sr--;
    sc--;
    for(int i=0;i<H;i++){
        string s;
        cin >> s;
        for(int j=0;j<W;j++){ 
            scheck[i][j] = false;
            mmap[i][j] = s[j];
        }
    }
    cin >> N;
    for(int i=0;i<N;i++){
        int fi, fj, F, D;
        struct Food f;
        cin >> f.i >> f.j >> f.F >> f.D;
        food.push_back({-double(f.F)/f.D, {f.i, f.j}});
    }
    sort(food.begin(), food.end());


    //

    // output
    int sum = 0;
    int ci = sr;
    int cj = sc;
    for(int i=0;i<int(food.size());i++){
        int ni = food[i].second.first;
        int nj = food[i].second.second;
        if(scheck[ni][nj]){
            continue;
        }
        string s = route(ci, cj, ni, nj);
        if(s.size() + sum > K){
            break;
        }else{
            sum += s.size();
            cout << s;
        }
        ci = ni;
        cj = nj;
    }
    for(int i=sum;i<K;i++){
        cout << '-';
    }
    cout << endl;

    return 0;
}
