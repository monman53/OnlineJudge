#include <iostream>
using namespace std;

int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};

bool data[12][12];

void dfs(int i,int j){
    data[i][j] = false;
    for(int k=0;k<4;k++){
        int ni=i+di[k];
        int nj=j+dj[k];
        if(ni >= 0 && ni < 12 && nj >= 0 && nj < 12){
            if(data[ni][nj]){
                dfs(ni,nj);
            }
        }
    }
}

int main(){
    string s;
    while(1){
        int count = 0;
        for(int i=0;i<12;i++){
            getline(cin,s);
            for(int j=0;j<12;j++){
                data[i][j] = s[j]=='1' ? true : false;
            }
        }

        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                if(data[i][j]){
                    count++;
                    dfs(i,j);
                }
            }
        }

        cout << count << '\n';

        if(!getline(cin,s)){
            break;
        }
    }
    return 0;
}
