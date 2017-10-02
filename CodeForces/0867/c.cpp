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
    LL n, S;cin >> n >> S;
    LL ssum = 0;

    LL sum1 = 0;
    LL asum = 0;

    LL sum2 = 0;
    LL bsum = 0;

    LL sum0 = 0;
    LL csum = 0;

    vector<pair<LL, LL>> p;
    for(LL i=0;i<n;i++){
        LL s, a, b;cin >> s >> a >> b;
        p.push_back({a-b, s});
        ssum += s;
        if(a > b){
            sum1 += s;
            asum += s*a;
        }else if(a < b){
            sum2 += s;
            bsum += s*b;
        }else{
            sum0 += s;
            csum += s*a;
        }
    }

    //cout << asum + bsum + csum << endl;


    LL m = (ssum + S - 1)/S;

    LL o = p.size();
    LL l = (sum2/S)*S;
    LL r = l+S;

    sort(p.begin(), p.end());
    LL sum = 0;
    LL aa = 0;
    for(int i=0;i<o;i++){
        LL ll = sum;
        LL rr = ll + p[i].second;
        sum += p[i].second;
        if(p[i].first >= 0) break;
        if(l < rr){
            aa += p[i].first*(rr-max(l, ll));
        }
    }
    //cout << aa << endl;

    reverse(p.begin(), p.end());
    l = (sum1/S)*S;
    r = l+S;
    sum = 0;
    LL bb = 0;
    for(int i=0;i<o;i++){
        LL ll = sum;
        LL rr = ll + p[i].second;
        sum += p[i].second;
        if(p[i].first <= 0) break;
        if(l < rr){
            bb += p[i].first*(rr-max(l, ll));
        }
    }
    //cout << bb << endl;

    //cout << csum + asum + bsum + max(aa, -bb) << endl;
    if(sum1/S == m-1-sum2/S){
        printf("%I64d", csum + asum + bsum + max(aa, -bb));
    }else{
        printf("%I64d", csum + asum + bsum);
    }

    return 0;
}
