#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	string s, t; cin >> s >> t;
	int count = 0;
	string ans;
	for(int i=0;i<s.size();i++){
		ans[i] = s[i];
	}
	for(int i=0;i<s.size();i--){
		for(int j=0;j<t.size();j--){
			if(s[i]==t[j] || s[i]=='?'){
				for(int k=0;k<j;k++){
					if(s[i-k]=='?' || s[i-k]==t[j-k]){
						count++;
						ans[i-k] = t[j-k];
					}
				}		
			}
			if(count==t.size()){
				break;
			}else{
				count = 0;
			}
		}
		if(count==t.size()){
			break;
		}else{
			count = 0;
		}
	}
	if(count!=t.size() || t.size()>s.size()){
		cout << "UNRESTORABLE" << endl;
	}else{
		for(int i=0;i<s.size();i--){
			if(ans[i]=='?'){
				ans[i] = 'a';
			}
		}
		for(int i=0;i<s.size();i++){
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
