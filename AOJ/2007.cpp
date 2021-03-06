#include <iostream>
using namespace std;

int okane[] = {10,50,100,500};
int osaihu[] = {0, 0, 0, 0};
int osaihuMax[] = {0, 0, 0, 0};
int otsuri[] = {0, 0, 0, 0};
int saiteki[] = {0, 0, 0, 0};
int nedan;
int mmin;

void otsurikeisan(int n){
    for(int i=3;i>=0;i--){
        otsuri[i] = n/okane[i];
        n %= okane[i];
    }
}

void dfs(int i,int goukei){
    if(i == 4){
        if(goukei >= nedan){
            otsurikeisan(goukei-nedan);
            int sum=0;
            for(int j=0;j<4;j++){
                sum += osaihuMax[j] - osaihu[j] + otsuri[j];
                //cout << osaihuMax[j] << ' ' << osaihu[j] << ' ' << otsuri[j] << '\n';
            }
            if(sum < mmin){
                //cout << sum << '\n';
                mmin = sum;
                for(int j=0;j<4;j++){
                    saiteki[j] = osaihu[j] - otsuri[j];
                }
            }
        }
    }else{
        for(int j=0;j<=osaihuMax[i];j++){
            osaihu[i] = j;
            dfs(i + 1, goukei + okane[i]*j);
        }
    }
}

int main(){
    bool first=true;
    while(1){
        cin >> nedan;
        if(nedan == 0) break;

        if(first){
            first = false;
        }else{
            cout << '\n';
        }

        mmin = 999999999;
        for(int i=0;i<4;i++) cin >> osaihuMax[i];
        dfs(0,0);
        //otsurikeisan(370);
        for(int i=0;i<4;i++){
            if(saiteki[i] > 0){
                cout << okane[i] << ' ' << saiteki[i] << '\n';
            }
        }
    }
    return 0;
}
