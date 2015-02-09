#include <iostream>
using namespace std;

int par[10000];
int mrank[10000];

int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(mrank[x] < mrank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(mrank[x] == mrank[y]) mrank[x]++;
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        par[i] = i;
        mrank[i] = 0;
    }

    int com,x,y;
    for(int i=0;i<q;i++){
        cin >> com >> x >> y;
        if(com == 0){
            unite(x,y);
        }else{
            cout << ((find(x) == find(y)) ? 1 : 0) << '\n';
        }
    }
    return 0;
}
