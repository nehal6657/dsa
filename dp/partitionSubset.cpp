#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;


ll subsett(int n, int k){
    if(n<k || !n || !k) return 0;
    vector<vector<long long int>> dp(k+1, vector<long long int> (n+1,0));
    for(int i=1;i<=k;i++){
        for(int j =1;j<=n;j++){
            if(j==i) dp[i][j] = 1;
            else if(j<i) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j-1] + dp[i][j-1]*i ;
        }
    }
    return dp[k][n];


}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<subsett(n,k)<<endl;
    return 0;
}