#include<bits/stdc++.h>
#include<limits>
using namespace std;
int minCostPath(vector< vector<int> >& nums) {
    int n = nums.size();
    int m = nums[0].size();
    vector< vector<int> > dp(n, vector<int>(m,0));
    for(int j = nums[0].size() -1 ;j>=0;j--){
        for(int i =  nums.size() -1 ; i>=0 ;i--){
            if(j== nums[0].size() -1 ) dp[i][j]=nums[i][j];
            else if (i==0) dp[i][j] = nums[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            else if (i== nums.size() -1 ) dp[i][j] = nums[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            else dp[i][j] = nums[i][j] + max( dp[i+1][j+1],max(dp[i][j+1], dp[i-1][j+1]));
        }
        
    }
    int m1   = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(dp[i][0] > m1 ) m1= dp[i][0]; 
    }
    return m1;

}
int main(){
    int m, n;
    cin>>n>>m;
    vector< vector<int> > v(n, vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>v[i][j];
    cout<<minCostPath(v);

    return 0;
}