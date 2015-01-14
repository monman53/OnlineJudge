#include <iostream>
#include <string>
using namespace std;

int main(){
    while(1){
        int n;
        string data[1000];
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n;i++){
            cin >> data[i];
            for(int j=0;;j++){
                if(data[i][j] == '.'){
                    if(data[i][j+1] != '.'){
                        data[i][j] = '+';
                        for(int k=i-1;k>0&&data[k][j]==' ';k--){
                            data[k][j] = '|';
                        }
                    }else{
                        data[i][j] = ' ';
                    }
                }else{
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << data[i] << '\n';
        }
    }
    return 0;
}
