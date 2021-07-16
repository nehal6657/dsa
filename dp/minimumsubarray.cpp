#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] =nums[0];
    int max1=dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        if(max1 < dp[i]) max1=dp[i];
    }
    for(auto i: dp) cout<<i<<" ";
    return max1;
    
}
int main(){

    return 0;
}