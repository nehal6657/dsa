#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

vector<string> getsubseq(string s){
    if(s=="") {
        ans.push_back("");
        vector<string> v1{""};
        return v1;
    }
    int n = s.length()-1;
    char x = s[0];
    string s1 = s.substr(1,n);
    vector<string> v1 = getsubseq(s1);
    for(auto i: v1){
        if(i!="")ans.push_back(i);
        ans.push_back(x+i);
    }
    return ans;

}
void psubseq(string s, string ans){
    if(s==""){
        cout<<ans<<" ";
        return ;
    }
    char s2=s[0];
    int n = s.length();
    string s1 = s.substr(1,n-1);
   
    psubseq(s1,ans+s2);
     psubseq(s1,ans);

}

int main(){
    vector<string> ans1;
    ans1 = getsubseq("abc");
    for(auto i: ans1){
        cout<<i<<endl;
    }
    cout<<"nehal\n";
    psubseq("yvTA","");


    return 0;
}