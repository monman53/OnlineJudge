#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans;
    ans = (a*b)%1000000007;
    ans = (ans*c)%1000000007;
    cout << ans << endl;
    return 0;
}
