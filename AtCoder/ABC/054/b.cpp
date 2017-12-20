// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    char a[50][50], b[50][50];
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0;i<m;i++){
        string s;cin >> s;
        for(int j=0;j<m;j++){
            b[i][j] = s[j];
        }
    }

    string ans = "No";
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool flag = true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l] != b[k][l]){
                        flag = false;
                    }
                }
            }
            if(flag){
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
    return 0;
}
