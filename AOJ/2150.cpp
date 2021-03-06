#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    bool isPrime[150000];
    int plist[100000];
    map<int, int> pcount;
    for(int i=0;i<150000;i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    int count=0;
    for(int i=2;i<150000;i++){
        if(isPrime[i]){
            pcount[i] = count;
            plist[count] = i;
            count++;
            for(int j=2;i*j<150000;j++){
                isPrime[i*j] = false;
            }
        }
    }
    while(1){
        int n,p;
        cin >> n >> p;
        if(n == -1 && p == -1) break;

        multiset<int> sum;
        for(int i=n+1;;i++){
            if(isPrime[i]){
                bool end=false;
                for(int j=pcount[i];!end;j++){
                    for(int k=pcount[i];k<=j;k++){
                        if(sum.size() < p){
                            sum.insert(plist[j] + plist[k]);
                        }else{ 
                            if(plist[j] + plist[k] <= *(--sum.end())){
                                sum.insert(plist[j] + plist[k]);
                                sum.erase(--sum.end());
                            }else if(k == pcount[i]){
                                cout << *(--sum.end()) << '\n';
                                end = true;
                                break;
                            }else{
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}
