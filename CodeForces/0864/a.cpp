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
    int n;cin >> n;
    vector<P> count(101);
    set<int> s;
    for(int i=0;i<101;i++){
        count[i] = {0, i};
    }
    for(int i=0;i<n;i++){
        int a;cin >> a;
        count[a].first++;
        s.insert(a);
    }
    if(int(s.size()) != 2){
        cout << "NO" << endl;
        return 0;
    }
    sort(count.begin(), count.end());
    for(int i=0;i<100;i++){
        if(count[i].first == 0) continue;
        if(count[i].first == count[i+1].first){
            cout << "YES" << endl;
            cout << count[i].second << " " << count[i+1].second << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
