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
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i-1;j>=0;j--){
            if(h[j] <= h[i]){
                count++;
            }else{
                break;
            }
        }
        for(int j=i+1;j<n;j++){
            if(h[j] <= h[i]){
                count++;
            }else{
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}
