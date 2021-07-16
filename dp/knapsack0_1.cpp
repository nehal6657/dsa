#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &wt, vector<int> &val, int maxwt){
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int> (maxwt+1,0));
    for(int i=1;i< val.size()+1; i++){
        for(int j = 1; j<= maxwt;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]]+ val[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[val.size()][maxwt];

}
int main(){
    int n = 5;
    //cin>>n;
    vector<int> wt{2,5,1,3,4}, val{15,14,10,45,30};
    
    // for(int i=0;i<n;i++) cin>>wt[i];
    // for(int i=0;i<n;i++) cin>>val[i];
    int target = 7;
    //cin>>target;
    cout<<knapsack(wt,val,target);

    return 0;
}