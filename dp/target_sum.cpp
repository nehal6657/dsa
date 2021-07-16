#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int> &arr, int target){
    int n= arr.size();
    vector< vector<bool> > dp(n+1,vector<bool> (target+1,0));
    
    for(int i=0;i<=n;i++){
        for(int j= 0;j<=target; j++){
            if(j==0 && i==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else if(j==0) dp[i][j] = 1;
            else {
                if( j<  arr[i-1]) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j= 0;j<=target; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i <= n; i++) if(dp[i][target]) return 1;
    return 0;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int target;
    cin>>target;
    cout<<targetSum(nums,target);

    return 0;
}