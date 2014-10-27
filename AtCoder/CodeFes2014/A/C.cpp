#include <iostream>
using namespace std;

bool data[10001];
int kazu[10001];

int count(long long int n){
    long long int ret=0;
    ret += (n/10000)*kazu[10000];
    //if(n%10000 != 0){    
        ret += kazu[n%10000];
        //}
    return ret;
}

int main(){
    for(int i=0;i<10001;i++){
        data[i] = false;
    }
    for(int i=0;i*4<10001;i++){
        data[i*4] = true;
    }
    for(int i=0;i*100<10001;i++){
        data[i*100] = false;
    }
    for(int i=0;i*400<10001;i++){
        data[i*400] = true;
    }
    int mcount=0;
    data[0] = false;
    for(int i=0;i<10001;i++){
        if(data[i]){
            mcount++;
        }
        kazu[i] = mcount;
    }

    int a,b;
    cin >> a >> b;
    //if((count(b-1) - count(a)
    cout << (count(b) - count(a-1)) << "\n";
    
    return 0;
}
