#include <iostream>
#include <vector>
#define MAX 9999999
using namespace std;

int n,m;
int sc[101];
int st[101][101];
int data[101][101][2];
int ans[101];

int calc(int p, int q, int r){
    for(int i=1;i<=m;i++) ans[i] = MAX;
    ans[p] = 0;
    while(1){
        bool change=false;
        for(int i=1;i<=m;i++){
            if(ans[i] != MAX){
                for(int j=0;j<sc[i];j++){
                    if(ans[i] + data[i][st[i][j]][r] < ans[st[i][j]]){
                        ans[st[i][j]] = ans[i] + data[i][st[i][j]][r];
                        change = true;
                    }
                }
            }
        }
        if(!change) break;
    }
    return ans[q];
}

int main(){
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1;i<=m;i++) sc[i] = 0;
        for(int i=0;i<n;i++){
            int a,b,cost,time;
            cin >> a >> b >> cost >> time;
            data[a][b][0] = data[b][a][0] = cost;
            data[a][b][1] = data[b][a][1] = time;
            st[a][sc[a]] = b;
            st[b][sc[b]] = a;
            sc[a] += 1;
            sc[b] += 1;
        }
        int k;
        cin >> k;
        for(int i=0;i<k;i++){
            int p,q,r;
            cin >> p >> q >> r;
            cout << calc(p,q,r) << '\n';
        }
    }
    return 0;
}
