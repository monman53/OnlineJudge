#include <iostream>
#include <map>
using namespace std;

int sum[1001][1001][3];

int main(){
    int m,n;
    int k;

    map<char,int> taiou;
    taiou['J'] = 0;
    taiou['O'] = 1;
    taiou['I'] = 2;

    for(int i=0;i<1001;i++){
        for(int j=0;j<3;j++){
            sum[0][i][j] = sum[i][0][j] = 0;
        }
    }

    cin >> m >> n;
    cin >> k;

    string s;
    for(int i=1;i<=m;i++){
        cin >> s;
        for(int j=1;j<=n;j++){
            for(int k=0;k<3;k++){
                sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] - sum[i-1][j-1][k];
                if(taiou[s[j-1]] == k){
                    sum[i][j][k] += 1;
                }
            }
        }
    }
    int a,b,c,d;
    for(int i=0;i<k;i++){
        cin >> a >> b >> c >> d;
        cout << (sum[c][d][0] - sum[c][b-1][0] - sum[a-1][d][0] + sum[a-1][b-1][0]) << ' '
             << (sum[c][d][1] - sum[c][b-1][1] - sum[a-1][d][1] + sum[a-1][b-1][1]) << ' '
             << (sum[c][d][2] - sum[c][b-1][2] - sum[a-1][d][2] + sum[a-1][b-1][2]) << '\n';
    }

    return 0;
}
