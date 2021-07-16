#include<bits/stdc++.h>
using namespace std;

int coinPermutations(vector<int> &nums, int target){
    int dp[target+1] = {0};
    dp[0] = 1;

    for(int i = 1;i<=target;i++){
        for(auto coin : nums){
            if(coin <= i){
                dp[i] += dp[i-coin];
            }
        }
    }
    return dp[target];


}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int target;
    cin>>target;
    cout<<coinPermutations(nums,target);

    return 0;
}