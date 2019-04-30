#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

const int MAX_N = 1 << 17;

int n;
long dataa[2*MAX_N - 1];
long datab[2*MAX_N - 1];

void init(int n_){
    n = 1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dataa[i] = -2000000000;
        datab[i] = 2000000000;
    }
}

void updatea(int k, long a){
    k += n-1;
    dataa[k] = a;
    while(k>0){
        k=(k-1)/2;
        dataa[k]=max(dataa[k*2+1], dataa[k*2+2]);
    }
}

void updateb(int k, long a){
    k += n-1;
    datab[k] = a;
    while(k>0){
        k=(k-1)/2;
        datab[k]=min(datab[k*2+1], datab[k*2+2]);
    }
}

long querya(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return dataa[k];
    else{
        long vl = querya(a, b, k*2+1, l, (l+r)/2);
        long vr = querya(a, b, k*2+2, (l+r)/2, r);
        return max(vl, vr);
    }
}

long queryb(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return 2000000000;
    if(a <= l && r <= b) return datab[k];
    else{
        long vl = queryb(a, b, k*2+1, l, (l+r)/2);
        long vr = queryb(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
}

int main(){
    int nn;
    cin >> nn;
    init(nn);
    for(int i=0;i<nn;i++){
        int a;
        cin >> a;
        updatea(i, a);
    }
    for(int i=0;i<nn;i++){
        int b;
        cin >> b;
        updateb(i, b);
    }
    int count = 0;
    for(int i=0;i<nn;i++){
        for(int j=i;j<nn;j++){
            cout << i << " " << j << " " << queryb(i, j+1, 0, 0, nn) << endl;
            if(querya(i, j, 0, 0, nn) == queryb(i, j, 0, 0, nn)){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
