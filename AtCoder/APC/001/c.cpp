#include <cstdio>
using namespace std;

int main() {
    int n;
    char s[100];

    scanf("%d", &n);

    printf("%d\n", 0);
    fflush(stdout);
    scanf("%s", s);
    if(s[0] == 'V') return 0;

    char c = s[0];

    int l = 0;
    int r = n;
    int m;
    while(r-l>1){
        //cout << l << " " << r << endl;
        m = (r+l)/2;

        printf("%d\n", m);
        fflush(stdout);
        scanf("%s", s);
        if(s[0] == 'V') return 0;

        if((s[0] != c && (m-l)%2 == 0) || (s[0] == c && (m-l)%2 != 0)){
            r = m;
        }else{
            c = s[0];
            l = m;
        }
    }
    printf("%d\n", m);
    fflush(stdout);
    scanf("%s", s);
    return 0;
}
