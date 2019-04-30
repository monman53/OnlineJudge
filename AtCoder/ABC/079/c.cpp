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

string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s;
    int ns[4] = {s[0]-'0', s[1]-'0', s[2]-'0', s[3]-'0'};
    char op[2] = {'+', '-'};
    for(int i=0;i<2;i++){
        int ni = ns[0] + (i?-ns[1]:ns[1]);
        for(int j=0;j<2;j++){
            int nj = ni + (j?-ns[2]:ns[2]);
            for(int k=0;k<2;k++){
                int nk = nj + (k?-ns[3]:ns[3]);
                if(nk == 7){
                    cout << s[0];
                    cout << op[i] << s[1];
                    cout << op[j] << s[2];
                    cout << op[k] << s[3];
                    cout << "=7" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
