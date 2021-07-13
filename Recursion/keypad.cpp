#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs; 
vector<string> codes={",;","abc","def","ghi","mno","pqrs","tu","vwx","yz"};
vs ans={};
vs keypad(string s){
    if(s==""){
        vs v1{""};
        return v1;
    }
    string t = s.substr(0,1);

    int n = s.length();
    string s1= s.substr(1,n-1);
    vs a1 = keypad(s1);
    int y = stoi(t);
    char m=s[0];
    vs vx;
    for(int i=0; i < codes[y].length();i++){
        for(auto i1: a1){
            vx.push_back(codes[y][i]+i1);
        }
    }
    return vx;


}

int main(){
    vs mx = keypad("215");
    for(auto i: mx) cout<<i<<" ";
    cout<<endl;

    return 0;
}