// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

struct Data {
    LL x[3];
};

int main() {
    vector<PII> x(3);
    for(int i=0;i<3;i++){
        LL n;
        cin >> n;
        x[i] = {n, i};
    }
    int n = x[0].first+x[1].first+x[2].first;
    vector<Data> data(n);
    for(int i=0;i<n;i++){
        LL a, b, c;cin >> a >> b >> c;
        data[i].x[0] = a;
        data[i].x[1] = b;
        data[i].x[2] = c;
    }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

    LL ans = 0;

    for(int i=0;i<3;i++){
        int m = x[i].first;
        int j = x[i].second;

        sort(data.begin(), data.end(), [&j](const Data &a, const Data &b){
                return a.x[j] > b.x[j];});
        for(int k=0;k<m;k++){
            ans += data[k].x[j];
            data[k].x[(j+1)%3] = 0;
            data[k].x[(j+2)%3] = 0;
        }
        
    }

    printf("%lld\n", ans);

    return 0;
}
