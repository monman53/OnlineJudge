#include <iostream>
using namespace std;

int w,h;
char data[20][20];
int mcount;

void dfs(int i,int j){
    mcount++;
    data[i][j]='$';
    for(int k=-1;k<=1;k+=2){
        if(i+k>=0 && i+k<h){
            if(data[i+k][j]=='.'){
                dfs(i+k,j);
            }
        }
        if(j+k>=0 && j+k<w){
            if(data[i][j+k]=='.'){
                dfs(i,j+k);
            }
        }
    }
}



int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 || h == 0){
            break;
        }
        int si,sj;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> data[i][j];
                if(data[i][j] == '@'){
                    si = i;
                    sj =j;
                }
            }
        }
        mcount=0;
        dfs(si,sj);
        cout << mcount <<'\n';
    }
    return 0;
}
