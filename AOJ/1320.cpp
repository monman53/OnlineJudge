// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int dist(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int ret = 0;
    for(int i=0;i<n1;i++){
        bool flag = true;
        int count = 0;
        for(int j=0;i+j<n1&&j<n2;j++){
            count++;
            if(s1[i+j] != s2[j]) flag = false;
        }
        if(flag) ret = max(ret, count);
    }
    return ret;
}

int dp[1<<16][16];

int main() {
    std::ios::sync_with_stdio(false);
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        vector<string> s(n);
        for(auto &ss : s) cin >> ss;

        int d[16][16];

        vector<int> v;

        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<n;j++){
                d[i][j] = dist(s[i], s[j]);
                if(dist(s[j], s[i]) == int(s[i].size()) && i != j){
                    flag = false;
                }
                //cout << d[i][j] << " ";
            }
            if(flag) v.push_back(i);
            //cout << endl;
        }
        n = v.size();

        memset(dp, -1, sizeof(dp));

        for(int i=0;i<n;i++){
            dp[1<<i][i] = 0;
        }

        for(int i=1;i<1<<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] != -1){
                    for(int k=0;k<n;k++){
                        if((1<<k & i) == 0){
                            int next = (i | 1 << k);
                            dp[next][k] = max(dp[next][k], dp[i][j]+d[v[j]][v[k]]);
                        }
                    }
                }
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += s[v[i]].size();
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, dp[(1<<n)-1][i]);
        }

        //cout << v.size() << " " << sum << " " << ans << endl;
        cout << sum-ans << endl;
    }
    return 0;
}
