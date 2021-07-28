#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int solve(string A) {
    int n = A.length();
    int N = n;
    vector<vector<int>> dp(N, vector<int> (N,0));
    for(int gap = 0; gap< N;gap++){
        for(int i=0, j = gap; j<n; i++,j++){
            if(gap == 0) dp[i][j]=1;
            else if (gap==1)
            {
                if(A[i]==A[j]) dp[i][j]=2;
                else dp[i][j]=1;
            }
            else{
                if(A[i] == A[j]) dp[i][j] = dp[i+1][j] + 2;
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s = "abkccbc";
    int n = solve(s);
    cout<<n<<endl;
    return 0;
}