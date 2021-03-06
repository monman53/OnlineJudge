#include <iostream>
using namespace std;

int data[100];

int find(int l, int r, int f, int count){

    if(r == l-1 || l == r+1){
        return count;
    }
    if(data[(l+r)/2] == f || r == l){
        return (count+1);
    }
    if(data[(l+r)/2] > f){
        return find(l,(l+r)/2-1,f,count+1);
    }else{
        return find((l+r)/2+1,r,f,count+1);
    }
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n;i++){
            cin >> data[i];
        }
        int f;
        cin >> f;
        cout << find(0,n-1,f,0) << '\n';
    }
    return 0;
}
