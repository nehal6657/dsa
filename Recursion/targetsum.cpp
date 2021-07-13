#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
void targetsum(vector<int> &v, int i, string ans,int sos,int target){
    if(i==v.size()){
        if(sos==target){
            cout<<ans<<endl;
        }
        return;
    }
    targetsum(v,i+1,ans+to_string(v[i]),sos+v[i],target);
    targetsum(v,i+1,ans,sos,target);
}


int main(){
    vector<int> v1 ={10,20,30,40,50};
    int t = 70;
    targetsum(v1,0,"",0,t);


    return 0;
}