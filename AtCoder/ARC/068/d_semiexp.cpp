#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
 
int N, A[101010];
int cnt[101010];
 
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    for (int i = 0; i < N; ++i) ++cnt[A[i]];
    sort(A, A + N);
 
    int ret = 0;
    for (int i = 1; i <= 100000; ++i) if (cnt[i]) ++ret;
    if (ret % 2 == 0) --ret;
    printf("%d\n", ret);
 
    return 0;
}
