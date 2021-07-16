#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &wt, vector<int> &val, int maxwt){
    int n = val.size();
    vector<int> dp(maxwt+1, 0);
    for(int i = 1;i <= maxwt; i++){    
        int x = 0;
        for(int j = 0;j<val.size();j++){
            if(wt[j] <= i){
                int y = dp[i-wt[j]] + val[j];
                x = max(x,y);
            }
        }
        dp[i] = x;
    }
    return dp[maxwt];

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