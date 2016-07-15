// sの左側に連続するaを取り除く(000888を888にするときなど)
//
// depends on
//  
string scutl(string s, char a){   // {{{
    int length = s.size();
    for(int i=0;i<length;i++){
        if(s[i] != a){
            return s.substr(i);
        }
    }
    return "";
}   // }}}


// sの右側に連続するaを取り除く(8880000を888にするときなど)
//
// depends on
// 
string scutr(string s, char a){   // {{{
    int length = s.size();
    for(int i=length-1;i>=0;i--){
        if(s[i] != a){
            return s.substr(0, i+1);
        }
    }
    return "";
}   // }}}


// sの左右に連続するaを取り除く(00008880000を888にするときなど)
//
// depends on
//  scutl
//  scutr
// 
string scutrl(string s, char a){   // {{{
    return scutr(scutl(s, a), a);
}   // }}}


// <T>ston(string s)  string型の数値をT型の数値に変換する
//
// #### C++11には<string>に標準で変換関数が用意されている。 ####
//  -> http://www.cplusplus.com/reference/string/
//
// depends on
#include <sstream>
//
template <typename T> T ston(string s){ // {{{
    stringstream ss;
    T ret;
    ss << s;
    ss >> ret;
    return ret;
}   // }}}
