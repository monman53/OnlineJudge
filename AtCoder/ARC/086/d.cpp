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

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++) cin >> a[i];

    int mmax = 0;
    int maxi = -1;
    for(int i=0;i<n;i++){
        if(mmax < abs(a[i])){
            mmax = abs(a[i]);
            maxi = i;
        }
    }
    if(a[maxi] > 0){
        for(int i=0;i<n;i++){
            if(a[i] < 0){
                ans.push_back({maxi, i});
            }
        }
        for(int i=0;i<n-1;i++){
            ans.push_back({i, i+1});
        }
    }else{
        for(int i=0;i<n;i++){
            if(a[i] > 0){
                ans.push_back({maxi, i});
            }
        }
        for(int i=n-1;i>0;i--){
            ans.push_back({i, i-1});
        }
    }

    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    return 0;
}
