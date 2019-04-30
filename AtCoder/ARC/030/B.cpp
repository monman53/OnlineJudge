#include <iostream>
#define INF 9999999
using namespace std;
int n,x;
bool check[101];
int hoseki[101];
int dir[101][101];
int dirc[101];
int ans=0;

void dfs(int x){
    check[x] = true;
    for(int i=0;i<dirc[x];i++){
        if(!check[dir[x][i]]){
            dfs(dir[x][i]);
            if(hoseki[dir[x][i]] == 1){
                hoseki[x] = 1;
                ans += 2;
            }
        }
    }
}

int main(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        check[i] = false;
        dirc[i] = 0;
        cin >> hoseki[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        dir[a][dirc[a]] = b;
        dir[b][dirc[b]] = a;
        dirc[a]++;
        dirc[b]++;
    }
    dfs(x);
    cout << ans << '\n';
    return 0;
}
