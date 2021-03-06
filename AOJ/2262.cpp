#include <iostream>
#include <map>
using namespace std;

bool check[20][20][16][4];
char data[20][20];
map<char, int> dir;
int r,c;
bool sugu;

int di[4]={0,-1,0,1};
int dj[4]={1,0,-1,0};

bool dfs(int ci,int cj,int m,int d){
    bool bcheck[20][20][16][4];
    bool result;
    while(1){
        if(ci < 0) ci = r-1;
        if(ci == r) ci = 0;

        if(cj < 0) cj = c-1;
        if(cj == c) cj = 0;

        if(m < 0) m = 15;
        if(m == 16) m = 0;

        if(check[ci][cj][m][d]){
            return false;
        }else{
            check[ci][cj][m][d] = true;
        }
        switch(data[ci][cj]){
        case '>':
        case '^':
        case '<':
        case 'v':
            d = dir[data[ci][cj]];
            sugu = false;
            break;
        case '_':
            d = ((m == 0) ? 0 : 2);
            sugu = false;
            break;
        case '|':
            d = ((m == 0) ? 3 : 1);
            sugu = false;
            break;
        case '?':
            result=false;
            if(sugu){
                return false;
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    for(int k=0;k<16;k++){
                        for(int l=0;l<4;l++){
                            bcheck[i][j][k][l] = check[i][j][k][l];
                        }
                    }
                }
            }
            for(int i=0;i<4;i++){
                sugu = true;
                result = result | dfs(ci+di[i],cj+dj[i],m,i);
                if(result) break;
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        for(int k=0;k<16;k++){
                            for(int l=0;l<4;l++){
                                check[i][j][k][l] = bcheck[i][j][k][l];
                            }
                        }
                    }
                }
            }
            if(result){
                return true;
            }else{
                return false;
            }
            break;
        case '.':
            d = d;//><
            break;
        case '@':
            return true;
            break;
        case '+':
            m++;
            break;
        case '-':
            m--;
            break;
        default:
            int n=int(data[ci][cj] - '0');
            m = n;
            break;
        }
        

        ci += di[d];
        cj += dj[d];
    }
}

int main(){
    dir['>'] = 0;
    dir['^'] = 1;
    dir['<'] = 2;
    dir['v'] = 3;

    cin >> r >> c;

    string s;

    for(int i=0;i<r;i++){
        cin >> s;
        for(int j=0;j<c;j++){
            data[i][j] = s[j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<16;k++){
                for(int l=0;l<4;l++){
                    check[i][j][k][l] = false;
                }
            }
        }
    }

    sugu = false;
    if(dfs(0,0,0,0)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
            
    return 0;
}
