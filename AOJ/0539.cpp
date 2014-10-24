#include <iostream>
#include <algorithm>
using namespace std;

int data[100001];

int find(int l,int r,int f){
    if(r-l == 1){
        return min(f-data[l],data[r]-f);
    }
    if(data[(l+r)/2] < f){
        return find((l+r)/2,r,f);
    }else{
        return find(l,(l+r)/2,f);
    }
}

int main(){
    while(1){
        int d,n,m;
        cin >> d;
        if(d == 0) break;
        cin >> n >> m;
        data[0] = 0;
        for(int i=1;i<n;i++){
            cin >> data[i];
        }
        data[n] = d;
        sort(data,data+n+1);
//        for(int i=0;i<n+1;i++){
//            cout << data[i] << '\n';
//        }

        int sum = 0;
        for(int i=0;i<m;i++){
            int f;
            cin >> f;
            sum += find(0,n,f);
        }
        cout << sum << '\n';
    }
    return 0;
}
