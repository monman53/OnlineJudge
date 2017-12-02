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
    int n;
    scanf("%d", &n);

    map<int, int> m;
    m[8] = 8;
    m[9] = 9;
    m[0] = 10;
    m[1] = 11;
    m[2] = 12;

    int ans[50];

    for(int i=0;i<(n+5-1)/5;i++){
        int q[50];
        for(int j=0;j<n;j++) q[j] = 0;
        for(int j=0, qq=1;j<5 && i*5+j<n;j++,qq*=10){
            q[i*5+j] = qq;
        }

        // q
        printf("?");
        fflush(stdout);
        for(int j=0;j<n;j++){
            printf(" %d", q[j]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);

        // res
        int res;
        scanf("%d", &res);
        for(int j=0;j<5 && i*5+j<n;j++){
            int w = m[res%10];
            if(w == 8 || w == 10 || w == 12){
                ans[i*5+j] = 0;
            }else{
                ans[i*5+j] = 1;
            }
            res -= w;
            res /= 10;
        }
    }

    printf("!");
    fflush(stdout);
    for(int i=0;i<n;i++){
        printf(" %d", ans[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}
