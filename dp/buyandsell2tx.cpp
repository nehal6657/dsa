#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v){
    int n = v.size();
    vector<int> vlr(n,0), vrl(n,0);
    int minn=v[0];
    for(int i=1;i<n;i++){
        vlr[i] = max(vlr[i-1], v[i]-minn);
        if(v[i] < minn) minn=v[i];
    }
    int maxx=v[n-1];
    for(int i=n-2;i>=0;i--){
        vrl[i] = max(vrl[i+1], maxx-v[i]);
        if(v[i] > maxx) maxx=v[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(ans < vlr[i]+vrl[i]) ans=vlr[i]+vrl[i];
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<profit(v)<<endl;
    return 0;
}