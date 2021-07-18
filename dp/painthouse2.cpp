#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int paint(vector<vector<int>> &cost, int k){
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int> (k,0));
    dp[0] = cost[0];
    int least0 = INT_MAX, least1 = INT_MAX;
    for(int j=0;j<k;j++){
        if(dp[0][j] <= least0){
            least1 = least0;
            least0 = dp[0][j];
        }
        else if(dp[0][j] <= least1){
            least1 = dp[0][j];
        }
    }

    for(int i=1;i<n;i++){
        int nleast0 = INT_MAX, nleast1 = INT_MAX;
        for(int j=0;j<k;j++){
            dp[i][j] = cost[i][j];
            if(least0 == dp[i-1][j]){
                dp[i][j]+=least1;
            }
            else{
                dp[i][j] += least0;
            }
            if(dp[i][j] <= nleast0){
                nleast1 = nleast0;
                nleast0 = dp[i][j];
            }
            else if(dp[i][j] <= nleast1){
                nleast1 = dp[i][j];
            }
        }
        least0 = nleast0;
        least1 = nleast1;
    }


    return least0;
}


int main(){
    // n houses, k colors
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(n, vector<int> (k,0));
    for(int i=0;i<n;i++){   
        for(int j=0; j<k; j++) {
            cin>>v[i][j];
        }
    }

    cout<<paint(v,k)<<endl;
    

    return 0;
}