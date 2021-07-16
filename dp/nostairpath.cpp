#include<iostream>
#include<vector>
#include<iostream>
using namespace std;

//memoisation
int stair(int n, vector<int> &v){
    if(n<0) return 0;
    if(n==0) return 1;
    if(v[n]) return v[n];
    int f1 = stair(n-1, v);
    int f2 = stair(n-2, v);
    int f3 = stair(n-3, v);
    int f = f1+f2 + f3;
    v[n] = f;
    return f;
}

int main(){
    int n=6;
    vector<int> v(n+1,0);
    int ans = stair(n,v);
    cout<<ans<<endl;

    //tabulation 
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        if(i==1) dp[i] = 1;
        else if(i==2) dp[i] = 2;
        else dp[i] = dp[i-1] + dp[i-2]+dp[i-3];
    }
    cout<<dp[n]<<endl;
    // with variable jumps
    vector<int> dp1(n+1,0);
    // for n = 6
    dp1[n] = 1;
    vector<int> var_maxjump={3,3,0,2,2,3};
    for(int i=n-1;i>=0;i--){
        for(int j = 1;j<=var_maxjump[i] && j<=n;j++){
            dp1[i] += dp1[i+j];
        }
    }
    for(auto i:dp1) cout<<i<<" ";
    cout<<dp1[0]<<endl;

    return 0;
}