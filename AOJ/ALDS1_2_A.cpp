#include <iostream>
using namespace std;

int main(){
  int n;
  int data[100];

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> data[i];
  }

  int count=0;
  bool flag = true;
  while(flag){
    flag = false;
    for(int j=n-1;j>=1;j--){
      if(data[j] < data[j-1]){
        int buf = data[j-1];
        data[j-1] = data[j];
        data[j] = buf;
        flag = true;
        count++;
      }
    }
  }

  for(int i=0;i<n;i++){
    cout << data[i];
    if(i != n-1){
      cout << " ";
    }
  }
  cout << '\n' << count << '\n';
}
