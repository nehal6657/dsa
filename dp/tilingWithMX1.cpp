#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int fun(int n,int m){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if(i<m) dp[i] = 1;
        else if(i==m) dp[i] = 2;
        else dp[i] = (i>m? dp[i-m]: 0) + (i>1? dp[i-1]:0);
    }
    return dp[n];
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<fun(n,m)<<endl;
    return 0;
}