#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v, int n, int fee){
    int profit=0,pf;
    int bp= -v[0], sp=0, cp = 0;
    int tb,ts,tc;
    for(int i=1;i<n;i++){
        tb = bp > cp-v[i] ? bp : cp-v[i];
        ts = bp + v[i] > sp ? bp + v[i] : sp;
        tc = sp>cp ? sp :cp;

        bp = tb, sp=ts, cp = tc;

    }

    return sp;
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