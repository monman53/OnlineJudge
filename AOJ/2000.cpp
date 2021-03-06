#include <iostream>
using namespace std;

int main(){
    int n,m,nowx,nowy,kaisyu;
    bool stone[21][21];
    int dx[] = { 0, 1, 0,-1};
    int dy[] = { 1, 0,-1, 0};
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int x=0;x<21;x++){
            for(int y=0;y<21;y++){
                stone[x][y] = false;
            }
        }
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            stone[x][y] = true;
        }

        cin >> m;
        nowx = 10;
        nowy = 10;
        kaisyu = 0;
        for(int i=0;i<m;i++){
            char c;            
            int l,dir;
            cin >> c >> l;
            if(c == 'N') dir = 0;
            if(c == 'E') dir = 1;
            if(c == 'S') dir = 2;
            if(c == 'W') dir = 3;
            for(int j=0;j<l;j++){
                nowx += dx[dir];
                nowy += dy[dir];
                if(stone[nowx][nowy]){
                    kaisyu++;
                    stone[nowx][nowy] = false;
                }
            }
        }
        if(kaisyu == n){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}
