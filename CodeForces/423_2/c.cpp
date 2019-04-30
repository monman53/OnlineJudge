// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

char ans[2000005];
char t[2000005];
int n, x, m, k, i, j, l;

int main() {
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%s", t);
        scanf("%d", &k);
        m = strlen(t);
        for(j=0;j<k;j++){
            scanf("%d", &x);
            x--;
            for(l=0;l<m;l++){
                ans[x+l] = t[l];
            }
        }
    }
    int len = 2000001;
    while(ans[len] == 0) len--;
    len++;
    for(int i=0;i<len;i++){
        if(ans[i] == 0) ans[i] = 'a';
    }
    printf("%s\n", ans);
    return 0;
}
