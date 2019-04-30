#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    
    double gpa[] = {4, 3, 2, 1, 0, 0};

    int n;
    string rs;

    cin >> n >> rs;

    double ans = 0;

    for(auto r : rs){
        ans += gpa[r-'A'];
    }

    printf("%0.10lf\n", ans/n);

    return 0;
}
