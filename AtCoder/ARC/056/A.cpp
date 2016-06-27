#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main(){

    long a, b, k, l;

    cin >> a >> b >> k >> l;

    cout << min((k/l)*b + (k%l)*a, (k/l + 1)*b) << endl;
    
    return 0;
}
