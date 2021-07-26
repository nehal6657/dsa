#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
int profit(vector<int> &v, int k){
    int n = v.size();
    vector< vector<int>> dp(k+1, vector<int> (n,0));
    for(int t=1;t<=k;t++){
        for(int d=1;d<n;d++){
            int maxx=dp[t][d-1];
            for(int pd = 0;pd< d;pd++){
                if((v[d] - v[pd]) + dp[t-1][pd] > maxx) maxx = v[d] - v[pd] + dp[t-1][pd];
            }
            dp[t][d] = maxx;
        }
    }
    return dp[k][n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;
    cin>>k;
    cout<<profit(v,k)<<endl;
    return 0;
}