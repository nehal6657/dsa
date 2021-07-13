#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

void pper(string s, string ans){
    if(s==""){
        cout<<ans<<" ";
        return;
    }
    for(int i =0;i<s.length();i++){
        string s1 = s.substr(0,i) + s.substr(i+1);
        pper(s1, ans+s[i]);
    }
}

int main(){
    string s ="12345";
    string s1 = s.substr(0,2) + s.substr(2+1);
    cout<<s1<<"nehal\n";
    pper("abc","");


    return 0;
}