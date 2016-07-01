#include <iostream>
#include <set>
using namespace std;

bool isPrime(int n){
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }

    for(int i=3;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << "YES\n";
    }
    
    set<int> s;

    bool hurui[1000001];
    for(int i=0;i<1000001;i++){
        hurui[i] = true;
    }
    for(int i=2;i<1000001;i++){
        if(hurui[i]){
            if(k%i == 0){
                s.insert(i);
            }
            for(int j=2;j*i<1000001;j++){
                hurui[i*j] = false;
            }
        }
    }
    // for(int i=2;i<=k;i++){
    //     if(isPrime(i)){
    //         if(k%i == 0){
    //             //cout << i << endl;
    //             s.insert(i);
    //             while(k%i == 0){
    //                 k /= i;
    //             }
    //         }
    //     }
    // }

    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        s.erase(c);
    }

    if(s.size() == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
