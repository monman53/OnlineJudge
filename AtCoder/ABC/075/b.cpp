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

int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};
// }}}


int main() {
    std::ios::sync_with_stdio(false);
    int h, w;cin >> h >> w;
    char c[50][50];
    for(int i=0;i<h;i++){
        string s;cin >> s;
        for(int j=0;j<w;j++){
            c[i][j] = s[j];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(c[i][j] == '.'){
                int count = 0;
                for(int k=0;k<8;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                        if(c[ni][nj] == '#'){
                            count++;
                        }
                    }
                }
                c[i][j] = char('0'+count);
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
