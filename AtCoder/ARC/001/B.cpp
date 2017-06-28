#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int diff = abs(B-A);

    int ans = 0;

    ans += (diff/10);
    
    int ext[] = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2};

    ans += ext[diff%10];

    cout << ans << endl;

    return 0;
}
