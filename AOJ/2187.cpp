#include <iostream>
using namespace std;

bool guse[9];
bool juse[9];
int gdata[9];
int jdata[9];
int gcount;

void dfs(int c, int g){
    if(c == 9){
        if(g > 4){
            gcount++;
        }
        return;
    }
    for(int i=0;i<9;i++){
        if(guse[i]){
            guse[i] = false;
            for(int j=0;j<9;j++){
                if(juse[j]){
                    juse[j] = false;
                    if(gdata[i] > jdata[j]){
                        dfs(c+1, g+1);
                    }else{
                        dfs(c+1 ,g);
                    }
                    juse[j] = true;
                }
            }
            guse[i] = true;
        }
    }
}

int main(){
    int n;
    for(int i=0;i<n;i++){
        for(int i=0;i<9;i++) cin >> gdata[i];
        for(int i=0;i<9;i++) cin >> jdata[i];
        for(int i=0;i<9;i++) guse[i] = juse[i] = true;
        gcount = 0;
        dfs(0,0);
        cout << double(gcount)/362880.0 << ' ' << (362880.0-double(gcount))/362880.0 << '\n';
    }
    return 0;
}
