// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, n;cin >> h >> w >> n;
    set<pair<int, int>> s;
    vector<LL> cnt(10, 0);
    cnt[0] = LL(h-2)*LL(w-2);
    for(int k=0;k<n;k++){
        int a, b;cin >> a >> b;a--;b--;
        int t = max(0, a-2);
        int d = min(h, a+3);
        int l = max(0, b-2);
        int r = min(w, b+3);
        //cout << t << d << l << r << endl;
        for(int i=0;i<d-t-2;i++){
            for(int j=0;j<r-l-2;j++){
                int count = 0;
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        int c = t+i+ii;
                        int d = l+j+jj;
                        if(s.find({c, d}) != s.end()){
                            count++;
                        }
                    }
                }
                cnt[count]--;
                cnt[count+1]++;
            }
        }
        //for(int i=0;i<10;i++) cout << cnt[i] << " ";
        //cout << endl;
        s.insert({a, b});
    }
    for(int i=0;i<10;i++){
        cout << cnt[i] << endl;
    }
    return 0;
}
