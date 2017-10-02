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

int n;

int c[200][200];
int di[] = {-1, -1, -1, 0};
int dj[] = {1, 0, -1, -1};

bool chack(int i, int j){
    for(int k=0;k<4;k++){
        int cnt = 0;
        for(int l=0;l<3;l++){
            int ni = i+di[k]*l;
            int nj = j+dj[k]*l;
            if(ni >= 0 && nj >= 0 && ni < n && nj < n){
                cnt += c[ni][nj];
            }else{
                cnt = 1;
                break;
            }
        }
        if(cnt == 0 || cnt == 3){
            return false;
        }
    }
    return true;
}

int solve(int i, int j) {
    if(i == n){
        //for(int ii=0;ii<n;ii++){
            //for(int jj=0;jj<n;jj++){
                //cout << c[ii][jj];
            //}
            //cout << endl;
        //}
        //cout << endl;
        return 1;
    }
    if(j == n) return solve(i+1, 0);

    int sum = 0;

    c[i][j] = 0;
    if(chack(i, j)){
        sum += solve(i, j+1);
    }

    c[i][j] = 1;
    if(chack(i, j)){
        sum += solve(i, j+1);
    }

    return sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    if(n > 4){
        cout << "2 8" << endl;
        return 0;
    }else if(n < 3){
        cout << "1 1" << endl;
        return 0;
    }else{
        cout << 2 << " " << solve(0, 0) << endl;
    }
    return 0;
}
