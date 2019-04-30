#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; ++i)
#define RREP(i,n) for(int i = 0; i >= n; ++i)
typedef priority_queue <int> pi;
typedef priority_queue <int, vector<int>, greater<int>> pg;
typedef unsigned long long int ulli;
typedef long long int lli;

//宣言
int A[100][100]; //マス
int ansI[1000], ansJ[1000], ans[1000]; //答え
int tempMN = 100000, tempMX = -100000; //仮で使うもの 最小　最大
int base; //基礎
int absI, absJ; //これも仮 絶対値



int main() {
    REP(i, 100)
    {
        REP(j, 100)
        {
            cin >> A[i][j];
            tempMN = min(tempMN, A[i][j]);
            tempMX = max(tempMX, A[i][j]);
        }
    }
    base = (tempMX - tempMN) / 100;
    REP(a, 1000)
    {
        tempMX = -100000; //初期化
        REP(i, 100)
        {
            REP(j, 100)
            {
                tempMX = max(tempMX, A[i][j]);
                if(tempMX == A[i][j]){
                    ansI[a] = i;
                    ansJ[a] = j;
                }
            }
        }
        if(tempMX < base)
        {
            ans[a] = tempMX;
        }else{
            ans[a] = base;
        }
        REP(i, 100)
        {
            REP(j, 100)
            {
                absI = ansI[a] - i;
                absJ = ansJ[a] - j;
                if (ans[a] - abs(absI) - abs(absJ) > A[i][j])
                {
                    ans[a] = A[i][j] + abs(absI) + abs(absJ);
                }
            }
        }
        REP(i, 100)
        {
            REP(j, 100)
            {
                absI = ansI[a] - i;
                absJ = ansJ[a] - j;
                if (ans[a] - abs(absI) - abs(absJ) > 0)
                {
                    A[i][j] = A[i][j] - (ans[a] - abs(absI) - abs(absJ));
                }
            }
        }
    }
    //ofstream outputfile("output.txt");
    //outputfile << 1000 << endl;
    cout << 1000;
    REP(i, 1000)
    {
        cout << endl << ansI[i] << " " << ansJ[i] << " " << ans[i];
    }
    /*REP(i, 100)
    {
        REP(j, 100)
        {
            outputfile << A[i][j] << " ";
        }
        outputfile << endl;
    }*/
}
