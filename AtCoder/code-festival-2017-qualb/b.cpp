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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int d[200000];
    for(int i=0;i<n;i++){
        cin >> d[i];
    }
    int m;cin >> m;
    int t[200000];
    map<int, int> mmap;
    for(int i=0;i<m;i++){
        cin >> t[i];
        mmap[t[i]] = 0;
    }
    for(int i=0;i<n;i++){
        mmap[d[i]]++;
    }
    for(int i=0;i<m;i++){
        if(mmap[t[i]] == 0){
            cout << "NO" << endl;
            return 0;
        }else{
            mmap[t[i]]--;
        }
    }
    cout << "YES" << endl;
    return 0;
}
