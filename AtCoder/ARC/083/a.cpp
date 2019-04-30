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
    int a, b, c, d, e, f;cin >> a >> b >> c >> d >> e >> f;
    int answ;
    int anss;
    double ans = -1;
    for(int i=0;i*a*100<=f;i++){
        for(int j=0;i*a*100+j*b*100<=f;j++){
            int w = i*a*100+j*b*100;
            if(w == 0) continue;
            for(int k=0;w+k*c<=f;k++){
                for(int l=0;l<=(f-w-k*c)/d;l++){
                    int s = k*c+l*d;
                    if(w+s>f) continue;
                    if(s>(i*a+j*b)*e) continue;
                    if(ans <= 100.0*double(s)/(double(w)+double(s))){
                        //cout << w << " " << s << endl;
                        ans = 100.0*double(s)/(double(w)+double(s));
                        answ = w;
                        anss = s;
                    }
                }
            }
        }
    }
    cout << (answ+anss) << " " << anss << endl;
    return 0;
}
