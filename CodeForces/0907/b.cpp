// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    char c[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            string s;cin >> s;
            for(int k=0;k<3;k++){
                c[i][j*3+k] = s[k];
            }
        }
    }

    int si, sj;cin >> si >> sj;si--;sj--;
    int i0 = si/3*3;
    int j0 = sj/3*3;
    int ti0 = si-i0;
    int tj0 = sj-j0;
    //int cnt = 0;
    //for(int i=0;i<3;i++){
        //for(int j=0;j<3;j++){
            //if(c[i0+i][j0+j] == '.') cnt++;
        //}
    //}
    //if(cnt > 0){
        //for(int i=0;i<3;i++){
            //for(int j=0;j<3;j++){
                //if(c[i0+i][j0+j] == '.'){
                    //c[i0+i][j0+j] = '!';
                //}
            //}
        //}
    //}else{
        int cnt = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(c[ti0*3+i][tj0*3+j] == '.') cnt++;
            }
        }
        if(cnt > 0){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(c[ti0*3+i][tj0*3+j] == '.'){
                        c[ti0*3+i][tj0*3+j] = '!';
                    }
                }
            }
        }else{
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(c[i][j] == '.'){
                        c[i][j] = '!';
                    }
                }
            }
        }
    //}

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << c[i][j];
            if(j%3 == 2) cout << " ";
        }
        cout << endl;
        if(i%3 == 2) cout << endl;
    }
    return 0;
}
