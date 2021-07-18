#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int tiling(int n){
    vector<int> dp(n,0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    cout<<tiling(n)<<endl;
    return 0;
}