#include <iostream>
#include <algorithm>
using namespace std;

void change(int n, int* m){
    if(*m > n/2) *m = n-*m+1;
}


int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        change(n, &x);
        change(n, &y);
        cout << (min(x,y)-1)%3+1 << '\n';
    }

    return 0;
}
