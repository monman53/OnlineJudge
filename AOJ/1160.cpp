#include <iostream>
using namespace std;

int data[50][50];
int h,w;
int di[] = {0,-1,-1,-1,0,1,1,1};
int dj[] = {1,1,0,-1,-1,-1,0,1};

void dfs(int ci,int cj){
    if(data[ci][cj] == 1){
        data[ci][cj] = 0;
        for(int i=0;i<8;i++){
            int ni = ci + di[i];
            int nj = cj + dj[i];
            if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                dfs(ni,nj);
            }
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> data[i][j];
            }
        }
        int count = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(data[i][j] == 1){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
