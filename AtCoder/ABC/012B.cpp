#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    printf("%02d:%02d:%02d\n",n/(60*60),(n/60)%60,n%(60));
    return 0;
}
