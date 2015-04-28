#include <iostream>
using namespace std;

char data[100][100];
int h,w;

void dfs(char kudamono,int i,int j){
    data[i][j] = '.';
    for(int k=-1;k<=1;k+=2){
        if(i+k >= 0 && i+k < h){
            if(data[i+k][j] == kudamono){
                dfs(kudamono,i+k,j);
            }
        }
        if(j+k >= 0 && j+k < w){
            if(data[i][j+k] == kudamono){
                dfs(kudamono,i,j+k);
            }
        }
    }
}

int main(){
    while(1){
        cin >> h >> w;
        if(h == 0 || w == 0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> data[i][j];
                //cout << data[i][j];
            }
            //cout << '\n';
        }
        int count=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(data[i][j]!='.'){
                    //cout << data[i][j];
                    count++;
                    dfs(data[i][j],i,j);
                    /*for(int k=0;k<h;k++){
                        for(int l=0;l<w;l++){
                            cout << data[k][l];
                        }
                        cout << "\n";
                    }
                    cout << '\n';
                    */
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
