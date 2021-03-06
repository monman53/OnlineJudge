#include <iostream>
using namespace std;

bool data[10][10];
bool check[10][10];

int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};

int mcount;

int dfs(int ci, int cj){
    int ni,nj;
    int ret=0;
    check[ci][cj] = false;
    mcount++;
    for(int i=0;i<4;i++){
        ni = ci + di[i];
        nj = cj + dj[i];
        if(ni >= 0 && ni < 10 && nj >= 0 && nj < 10){
            if(check[ni][nj]){// && !check[ni][nj]){
                ret += dfs(ni,nj);
            }
        }
    }
    if(ret == 0){
        return 1;
    }else{
        return ret;
    }
}


int main(){
    string s;
    int shima=0;
    for(int i=0;i<10;i++){
        cin >> s;
        for(int j=0;j<10;j++){
            if(s[j] == 'o'){
                data[i][j] = true;
                shima++;
            }else{
                data[i][j] = false;
            }
        }
    }
    bool ans=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(!data[i][j]){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        check[k][l] = data[k][l];
                    }
                }
                mcount = 0;
                check[i][j] = true;
                dfs(i,j);
                //cout << shima << ' ' << mcount << '\n';
                if(mcount == shima+1){
                    ans = true;
                    break;
                } 
                
            }
        }
    }

    cout << ((ans || shima == 100) ? "YES" : "NO") << '\n';

    return 0;
}
