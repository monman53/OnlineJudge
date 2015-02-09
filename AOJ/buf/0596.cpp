#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int dir[5001][5001];
    int dirc[5001];
    bool check[5001];
    int c[5001];
    int r[5001];
    for(int i=1;i<=n;i++){
        dirc[i] = 0;
        check[i] = false;
    }
    for(int i=1;i<=n;i++){
        cin >> c[i] >> r[i];
    }
    for(int i=0;i<k;i++){
        int f,t;
        cin >> f >> t;
        dir[f][dirc[f]] = t;
        dir[t][dirc[t]] = f;
        dirc[t]++;
        dirc[f]++;
    }

    queue<pair<int,int> > pq;

    return 0;
}
