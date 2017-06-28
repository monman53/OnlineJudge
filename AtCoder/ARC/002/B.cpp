#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {

    int n;
    string c;

    cin >> n >> c;

    int ans = n;

    for(auto l1 : "ABXY"){
        for(auto l2 : "ABXY"){
            for(auto r1 : "ABXY"){
                for(auto r2 : "ABXY"){
                    string L = "";
                    string R = "";

                    L += l1;
                    L += l2;
                    R += r1;
                    R += r2;

                    int count = 0;

                    for(int i=0;i<n-1;){
                        if(c.compare(i, 2, L) == 0 ||
                           c.compare(i, 2, R) == 0){ 
                            count++;
                            i+=2;
                        }else{
                            i++;
                        }
                    }

                    ans = min(ans, n-count);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
