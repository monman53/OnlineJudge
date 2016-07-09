#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ii[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    int jj[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    int di[n];
    int dj[n];
    int bi = ii[int(s[0]-'0')];
    int bj = jj[int(s[0]-'0')];
    for(int i=1;i<n;i++){
        int nowi = ii[int(s[i]-'0')];
        int nowj = jj[int(s[i]-'0')];
        di[i] = nowi - bi;
        dj[i] = nowj - bj;
        bi = nowi;
        bj = nowj;
    }

    if(n == 1){
        cout << "NO" <<endl;
        return 0;
    }

    int count = 0;
    for(int i=0;i<10;i++){
        int nowi = ii[i];
        int nowj = jj[i];
        for(int j=1;j<n;j++){
            nowi += di[j];
            nowj += dj[j];
            if(nowi >= 0 && nowi < 4 && nowj >= 0 && nowj < 3){
                if((nowi == 3 && nowj == 0) || (nowi == 3 && nowj == 2)){
                    break;
                }
            }else{
                break;
            }
            if(j == n-1){
                count++;
            }
        }
    }

    if(count == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
