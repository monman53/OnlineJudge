#include <iostream>
using namespace std;

int main(){
    int dir[11][11];
    int dirc[11];
    for(int i=0;i<11;i++){
        dirc[i] = 0;
    }
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        dir[a][dirc[a]] = b;
        dir[b][dirc[b]] = a;
        dirc[a]++;
        dirc[b]++;
    }
    bool check[11];
    for(int i=1;i<=n;i++){
        for(int j=0;j<11;j++){
            check[j] = true;
        }
        check[i] = false;
        for(int j=0;j<dirc[i];j++){
            check[dir[i][j]] = false;
        }
        int count=0;
        for(int j=0;j<dirc[i];j++){
            for(int k=0;k<dirc[dir[i][j]];k++){
                if(check[dir[dir[i][j]][k]]){
                    check[dir[dir[i][j]][k]] = false;
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
