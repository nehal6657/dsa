#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int cnt(vector<int> &v, int n){
    int dp[2][n]={0};
    dp[0][0] = v[0];
    dp[1][0] = 0;
    for(int i=1;i<n;i++){
        dp[0][i] = dp[1][i-1] + v[i];
        dp[1][i] = max(dp[1][i-1], dp[0][i-1]); 
    }
    return max(dp[0][n-1],dp[1][n-1]);
}



int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    cout<<cnt(v,n);

    return 0;
}