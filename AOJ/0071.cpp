#include <iostream>
using namespace std;

bool data[8][8];

int di[4] = {0,-1,0,1};
int dj[4] = {1,0,-1,0};

void dfs(int i, int j){
    int ni,nj;
    data[i][j] = false;
    for(int k=0;k<4;k++){
        for(int l=1;l<=3;l++){
            ni = i + l*di[k];
            nj = j + l*dj[k];
            if(ni >= 0 && ni < 8 && nj >= 0 && nj < 8){
                if(data[ni][nj]) dfs(ni,nj);
            }else{
                break;
            }
        }
    }
}

int main(){
    int n;
    int x,y;
    string s;
    cin >> n;
    for(int k=0;k<n;k++){
        for(int i=0;i<8;i++){
            cin >> s;
            for(int j=0;j<8;j++) data[i][j] = (s[j] == '1') ? true : false;
        }
        cin >> x >> y;
        dfs(y-1,x-1);

        cout << "Data " << (k+1) << ":\n";
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout << ((data[i][j]) ? '1' : '0');
            }
            cout << '\n';
        }
    }
    return 0;
}
