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

LL mat[100][100];
LL mmax[100][100];
LL mmin[100][100];
LL ans[100][100];

int solve() {
    LL h, w;cin >> h >> w;
    inc(i, 0, h){
        inc(j, 0, w){
            cin >> mat[i][j];
        }
    }

    // i
    inc(i, 0, h){
        LL hoge = 1;
        inc(j, 0, w){
            if(mat[i][j] == -1){
                mmin[i][j] = hoge;
            }else{
                if(mat[i][j] < hoge){
                    return 0;
                }else{
                    hoge = mat[i][j];
                }
            }
        }
    }
    inc(i, 0, h){
        LL hoge = 2000000000;
        dec(j, 0, w){
            if(mat[i][j] == -1){
                mmax[i][j] = hoge;
            }else{
                if(mat[i][j] > hoge){
                    return 0;
                }else{
                    hoge = mat[i][j];
                }
            }
        }
    }

    // j
    inc(j, 0, w){
        LL hoge = 1;
        inc(i, 0, h){
            if(mat[i][j] == -1){
                mmin[i][j] = max(hoge, mmin[i][j]);
                hoge = max(hoge, mmin[i][j]);
            }else{
                if(mat[i][j] < hoge){
                    return 0;
                }else{
                    hoge = mat[i][j];
                }
            }
        }
    }
    inc(j, 0, w){
        LL hoge = 2000000000;
        dec(i, 0, h){
            if(mat[i][j] == -1){
                mmax[i][j] = min(hoge, mmax[i][j]);
                hoge = min(hoge, mmax[i][j]);
            }else{
                if(mat[i][j] > hoge){
                    return 0;
                }else{
                    hoge = mat[i][j];
                }
            }
        }
    }

    inc(k, 0, 100){
        // i
        inc(i, 0, h){
            LL hoge = 1;
            inc(j, 0, w){
                if(mat[i][j] == -1){
                    mmin[i][j] = max(hoge, mmin[i][j]);
                    hoge = max(hoge, mmin[i][j]);
                }else{
                    if(mat[i][j] < hoge){
                        return 0;
                    }else{
                        hoge = mat[i][j];
                    }
                }
            }
        }
        inc(i, 0, h){
            LL hoge = 2000000000;
            dec(j, 0, w){
                if(mat[i][j] == -1){
                    mmax[i][j] = min(hoge, mmax[i][j]);
                    hoge = min(hoge, mmax[i][j]);
                }else{
                    if(mat[i][j] > hoge){
                        return 0;
                    }else{
                        hoge = mat[i][j];
                    }
                }
            }
        }

        // j
        inc(j, 0, w){
            LL hoge = 1;
            inc(i, 0, h){
                if(mat[i][j] == -1){
                    mmin[i][j] = max(hoge, mmin[i][j]);
                    hoge = max(hoge, mmin[i][j]);
                }else{
                    if(mat[i][j] < hoge){
                        return 0;
                    }else{
                        hoge = mat[i][j];
                    }
                }
            }
        }
        inc(j, 0, w){
            LL hoge = 2000000000;
            dec(i, 0, h){
                if(mat[i][j] == -1){
                    mmax[i][j] = min(hoge, mmax[i][j]);
                    hoge = min(hoge, mmax[i][j]);
                }else{
                    if(mat[i][j] > hoge){
                        return 0;
                    }else{
                        hoge = mat[i][j];
                    }
                }
            }
        }
    }


    inc(i, 0, h){
        inc(j, 0, w){
            if(mat[i][j] == -1){
                if(mmin[i][j] > mmax[i][j]){
                    return 0;
                }else{
                    ans[i][j] = mmin[i][j];
                }
            }else{
                ans[i][j] = mat[i][j];
            }
        }
    }

    inc(i, 0, h){
        inc(j, 0, w){
            cout << ans[i][j];
            if(j != w-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 1;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--){
        if(!solve()){
            cout << -1 << endl;
        }
    }
    return 0;
}
