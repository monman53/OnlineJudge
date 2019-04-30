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
    int x[2000], y[2000];
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> x[i];
        s.insert(x[i]);
    }
    for(int j=0;j<n;j++){
        cin >> y[j];
        s.insert(y[j]);
    }

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s.find(x[i]^y[j]) != s.end()){
                count++;
            }
        }
    }
    if(count%2 == 0){
        cout << "Karen" << endl;
    }else{
        cout << "Koyomi" << endl;
    }
    return 0;
}
