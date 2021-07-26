#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v, int n){
    int ans=0;
        for(int i=1;i<v.size();i++){
            ans+= max(0, v[i]-v[i-1]);
        }
        return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<profit(v,n)<<endl;
    return 0;
}