#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int cnt(string s){
    int a = 0, ab= 0, abc = 0;
    for(char i: s){
        if(i=='a') a= 2*a + 1;
        else if(i=='b') ab = 2*ab + a;
        else abc = 2*abc + ab;
    }
    return abc;


}



int main(){
    string s;
    cin>>s;
    cout<<cnt(s);

    return 0;
}