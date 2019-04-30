// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    char c[50][50];
    int h, w;cin >> h >> w;
    int si, sj;
    for(int i=0;i<h;i++){
        string s;cin >> s;
        for(int j=0;j<w;j++){
            c[i][j] = s[j];
            if(c[i][j] == 'S'){
                si = i;
                sj = j;
            }
        }
    }
    string s;cin >> s;
    int di[] = {0, -1, 0, 1};
    int dj[] = {1, 0, -1, 0};
    vector<int> m = {0, 1, 2, 3};
    int ans = 0;
    do{
        int ci = si;
        int cj = sj;
        for(auto cc : s){
            int k = m[cc-'0'];
            ci += di[k];
            cj += dj[k];
            if(ci >= 0 && ci < h && cj >= 0 && cj < w){
                if(c[ci][cj] == '#'){
                    break;
                }
                if(c[ci][cj] == 'E'){
                    ans++;
                    break;
                }
            }else{
                break;
            }
        }
        //for(int i=0;i<4;i++) cout << m[i] << " ";
        //cout << endl;
    }while(next_permutation(m.begin(), m.end()));
    cout << ans << endl;
    return 0;
}
