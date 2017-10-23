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
int n;
int sum[200001][ALPHABET];
int memo[200000];

int solve(int l) {
    if(memo[l] != -1){
        return memo[l];
    }
    if(l == n) return 0;
    memo[l] = n*2;
    for(int i=l+1;i<=n;i++){
        int count = 0;
        for(int j=0;j<ALPHABET;j++){
            if((sum[i][j]-sum[l][j])%2 == 1){
                count++;
            }
        }
        if(count < 2){
            memo[l] = min(memo[l], solve(i)+1);
        }
    }
    return memo[l];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    memset(sum, 0, sizeof(sum));
    memset(memo, -1, sizeof(memo));
    for(int i=0;i<n;i++){
        for(int j=0;j<ALPHABET;j++){
            sum[i+1][j] = sum[i][j];
        }
        sum[i+1][s[i]-'a']++;
    }
    //solve(0);

    int count = 0;
    for(int i=0;i<ALPHABET;i++){
        if(sum[n][i]%2 == 1){
            count++;
        }
    }
    cout << memo[0] << endl;
    return 0;
}
