#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v, int n, int fee){
    int profit=0,pf;
    int bd= -v[0], sd=0;
    for(int i=1;i<n;i++){
        if(bd < (sd -v[i])) bd = sd-v[i];
        if(sd < bd + v[i] - fee) sd = bd + v[i] - fee;
    }

    return sd;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int fee;
    cin>>fee;
    cout<<profit(v,n,fee)<<endl;
    return 0;
}