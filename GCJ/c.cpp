// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int ok[100][100];
const int h = 5;
const int w = 5;

bool check(int ci, int cj) {
    int cnt = 0;
    inc(i, 0, 3){
        inc(j, 0, 3){
            cnt += ok[ci*3+i+1][cj*3+j+1];
        }
    }
    return cnt == 9;
}

int main() {
    //cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        int a;cin >> a;
        mset(ok, 0);

        inc(i, 0, h){
            inc(j, 0, w){
                int ai, aj;
                while(!check(i, j)){
                    int oi = i*3+2;
                    int oj = j*3+2;
                    cout << oi << " " << oj << endl;
                    cin >> ai >> aj;
                    if(ai == 0 && aj == 0){
                        i = h;
                        j = w;
                        break;
                    }
                    if(ai == -1 && aj == -1){
                        return 0;
                    }
                    ok[ai][aj] = 1;
                }
            }
        }
    }
    return 0;
}
