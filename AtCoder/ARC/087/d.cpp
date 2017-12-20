// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}
int dpx[5000][10000];
int dpy[5000][10000];


int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;s.push_back('T');
    int x, y;cin >> x >> y;
    int n = s.size();
    vector<int> xx;
    vector<int> yy;
    int b = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'T'){
            if(count%2 == 0){
                xx.push_back(i-b);
            }else{
                yy.push_back(i-b);
            }
            count++;
            b = i+1;
        }
    }
    int nx = xx.size();
    memset(dpx, 0, sizeof(dpx));
    dpx[0][5000] = 1;
    for(int i=0;i<nx;i++){
        for(int j=0;j<10000;j++){
            if(dpx[i][j] == 1){
                dpx[i+1][j+xx[i]] = 1;
                if(i != 0){
                    dpx[i+1][j-xx[i]] = 1;
                }
            }
        }
    }
    int ny = yy.size();
    memset(dpy, 0, sizeof(dpy));
    dpy[0][5000] = 1;
    for(int i=0;i<ny;i++){
        for(int j=0;j<10000;j++){
            if(dpy[i][j] == 1){
                dpy[i+1][j+yy[i]] = 1;
                dpy[i+1][j-yy[i]] = 1;
            }
        }
    }
    //cout << dpx[nx][5000+x] << " " << dpy[ny][5000+y] << endl;
    if(dpx[nx][5000+x] == 1 && dpy[ny][5000+y] == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
