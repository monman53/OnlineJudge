#include <iostream>
using namespace std;

int main(){
    int blockdi[7][3] = {{0,1,1},
                         {1,2,3},
                         {0,0,0},
                         {1,1,2},
                         {0,1,1},
                         {1,1,2},
                         {0,1,1}};
    int blockdj[7][3] = {{1,0,1},
                         {0,0,0},
                         {1,2,3},
                         {0,-1,-1},
                         {1,1,2},
                         {0,1,1},
                         {1,0,-1}};
    bool data[8][8];

    while(1){
        bool end=false;
        string s;
        for(int i=0;i<8;i++){
            cin >> s;
            //cout << s << '\n';
            if(cin.eof()){
                end = true;
                break;
            }
            for(int j=0;j<8;j++) data[i][j] = (s[j] == '1') ? true : false;
        }
        if(end) break;
        end = false;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(data[i][j]){
                    int count;
                    int ni,nj;
                    for(int k=0;k<7;k++){
                        count = 0;
                        for(int l=0;l<3;l++){
                            ni = i + blockdi[k][l];
                            nj = j + blockdj[k][l];
                            if(ni >= 0 && ni < 8 && nj >= 0 && ni < 8){
                                if(data[ni][nj]) count++;
                            }
                        }
                        if(count == 3){
                            cout << char('A' + k) << '\n';
                            break;
                        }
                    }
                    end = true;
                    break;
                }
            }
            if(end) break;
        }

    }
    return 0;
}
