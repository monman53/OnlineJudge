#include <iostream>
using namespace std;

char data[100][100];

int h,w;

void dfs(int i,int j){
    data[i][j] = '.';
    for(int k=-1;k<=1;k++){
        for(int l=-1;l<=1;l++){
            if(i+k >= 0 && i+k < h && j+l >= 0 && j+l <w){ 
                if(data[i+k][j+l]=='W'){
                    dfs(i+k,j+l);
                }
            }
        }
    }
}

int main(){
    int count=0;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> data[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j] == 'W'){
                count++;
                dfs(i,j);
            }
        }
    }
    cout << count << '\n';
    return 0;
}
