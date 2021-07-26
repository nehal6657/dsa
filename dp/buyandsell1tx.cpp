#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v, int n){
    int min=v[0], maxx=0;
    for(int i=0;i<n;i++){
        if(maxx < v[i] - min) maxx = v[i]-min;
        if(v[i] < min) min = v[i];
    }
    return maxx;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<profit(v,n)<<endl;
    return 0;
}