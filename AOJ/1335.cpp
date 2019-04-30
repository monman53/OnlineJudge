#include <iostream>
#include <set>
using namespace std;

int n,k,s;

set<set<int> > ans;
set<int> addset;
int add[10];

void calc(int i, int b, int sum){
    if(i==k){
        if(sum == s) ans.insert(addset);
        return;
    }
    for(int j=b+1;j<=n;j++){
        if(sum+j>s){
            break;
        }else{
            addset.insert(j);
            calc(i+1, j, sum+j);
            addset.erase(j);
        }
    }
}

int main(){
    while(1){
        cin >> n >> k >> s;
        if(n+k+s == 0) break;
        ans.clear();
        addset.clear();
        calc(0,0,0);
        cout << ans.size() << '\n';
    }
    return 0;
}
