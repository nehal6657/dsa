#include<iostream>
#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> dp(n+1,INT_MAX);
    dp[n] = 0;
    for(int i=n-1; i>=0; i--){
        int x = INT_MAX;
        for(int j = 1;j<=v[i] && i+j<=n; j++){
            x = min(x,dp[i+j]);    
        }
        if(x!=INT_MAX)
            dp[i]=x+1;
    }
    for(auto i:dp) cout<<i<<" ";

    cout<<dp[0]<<endl;
    return 0;
}