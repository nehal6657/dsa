#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int> &arr, int target){
    int n= arr.size();
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(auto coin: arr){
        for(int j = 1; j<=target; j++){
            int x = j - coin;
            if(x >= 0){
                dp[j] += dp[x];
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
    cout<<targetSum(nums,target);

    return 0;
}