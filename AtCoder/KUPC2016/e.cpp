// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int h, w;
char cmap[102][102];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

void dfs(int i, int j) {
    if(cmap[i][j] != '.') return;
    cmap[i][j] = 'w';
    for(int k=0;k<4;k++){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(0 <= ni && ni < h+2 && 0 <= nj && nj < w+2){
            dfs(ni, nj);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    for(int i=0;i<h+2;i++){
        for(int j=0;j<h+2;j++){
            cmap[i][j] = '.';
        }
    }
    for(int i=0;i<h;i++){
        string s;cin >> s;
        for(int j=0;j<w;j++){
            cmap[i+1][j+1] = s[j];
            if(i == 0 || i == h-1 || j == 0 || j == w-1){
                if(s[j] == 'X'){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(cmap[i][j] == 'X'){
                for(int k=0;k<4;k++){
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(cmap[ni][nj] == '.'){
                        cmap[ni][nj] = '#';
                    }
                }
            }
        }
    }
    dfs(0, 0);
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            //cout << cmap[i][j];
            if(cmap[i][j] == '#'){
                for(int k=0;k<4;k++){
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(cmap[ni][nj] == 'w'){
                        ans++;
                        break;
                    }
                }
            }
        }
        //cout << endl;
    }
    cout << ans << endl;

    return 0;
}
