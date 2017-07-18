// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int main() {
    int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};
    char c[10][10];
    int n = 10;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int j=0;j<n;j++){
            c[i][j] = s[j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                int count = 0;
                for(int l=0;l<5;l++){
                    int ni = i + di[k]*l;
                    int nj = j + dj[k]*l;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n){
                        if(c[ni][nj] == 'X') count++;
                        if(c[ni][nj] == 'O') break;
                    }else{
                        break;
                    }
                    if(l == 4 && count == 4){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
