#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, K;

    // input
    cin >> N >> K;

    vector<int> R(N);

    for(auto &r : R){
        cin >> r;
    }

    // solve
    double ans = 0;

    sort(R.begin(), R.end());

    for(int i=N-K;i<N;i++){
        ans = (ans + R[i])/2;
    }

    // output 
    printf("%.8lf\n", ans);

    return 0;
}
