#include <iostream>
#include <string>
using namespace std;

char data[20][20];
int h,w,mcount;
int di[] = {0,-1,0,1};
int dj[] = {1,0,-1,0};

void dfs(int ci, int cj){
    if(data[ci][cj] == '#'){
        return;
    }
    if(data[ci][cj] == '.' || data[ci][cj] ==  '@'){
        data[ci][cj] = '#';
        mcount++;
    }
    for(int i=0;i<4;i++){
        int ni = ci + di[i];
        int nj = cj + dj[i];
        if(ni >= 0 && ni < h && nj >= 0 && nj < w){
            dfs(ni,nj);
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        int si,sj;
        for(int i=0;i<h;i++){
            string s;
            cin >> s;
            for(int j=0;j<w;j++){
                data[i][j] = s[j];
                if(s[j] == '@'){
                    si = i;
                    sj = j;
                }
            }
        }
        mcount = 0;
        dfs(si,sj);
        cout << mcount << '\n';
    }
    return 0;
}
