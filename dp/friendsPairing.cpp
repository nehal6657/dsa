#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int pairing(int n){
    int dp[n+1]={0};
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + ((i-1) * dp[i-2]);

    }
    return dp[n];
}

int main(){
    int n,m;
    cin>>n;
    cout<<pairing(n)<<endl;

    return 0;
}