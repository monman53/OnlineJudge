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

int main() {
    std::ios::sync_with_stdio(false);
    int h, w;cin >> h >> w;
    char a[100][100];
    int count[ALPHABET];
    for(int i=0;i<ALPHABET;i++){
        count[i] = 0;
    }
    for(int i=0;i<h;i++){
        string s;cin >> s;
        for(int j=0;j<w;j++){
            a[i][j] = s[j];
            count[a[i][j]-'a']++;
        }
    }

    string ans = "Yes";

    int center;
    int cross;
    if(h%2 == 0 && w%2 == 0){
        center = 0;
        cross = 0;
    }
    if(h%2 == 0 && w%2 == 1){
        center = 0;
        cross = h;
    }
    if(h%2 == 1 && w%2 == 0){
        center = 0;
        cross = w;
    }
    if(h%2 == 1 && w%2 == 1){
        center = 1;
        cross = h+w-2;
    }

    int other = h*w - center - cross;
    for(int i=0;i<ALPHABET;i++){
        if(count[i]%2 == 0){
            cross -= count[i]%4;
            int toother = (count[i]/4)*4;
            if(other < toother){
                cross -= toother-other;
                other = 0;
            }else{
                other -= toother;
            }
        }else{
            if(h%2 == 0 || w%2 == 0) ans = "No";
            center--;
            cross -= (count[i]-1)%4;
            int toother = ((count[i]-1)/4)*4;
            if(other < toother){
                cross -= toother-other;
                other = 0;
            }else{
                other -= toother;
            }
        }
        if(center < 0 || cross < 0 || other < 0) ans = "No";
    }

    cout << ans << endl;

    return 0;
}
