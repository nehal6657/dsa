#include<bits/stdc++.h>
using namespace std;
int encodings(string s){
    int n = s.length();
    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i=1;i<n; i++){
        if(s[i]== '0' && s[i+1]=='0'){
            dp[i] = 0;
        }
        else if (s[i-1]=='0')
        {
            dp[i] = dp[i-1];
        }
        else if(s[i] == '0'){
            string last2 = s.substr(i-1,2);
            int y = stoi(last2);
            if(y<=26){
                dp[i] = i>=2 ? dp[i-2]: 1;
            }
            else{
                dp[i] = 0;
            }

        }
        else{
            string last2 = s.substr(i-1,2);
            int y = stoi(last2);
            dp[i]=dp[i-1];
            if(y<=26){
                dp[i] += i>=2? dp[i-2]: 1; 
            }
        }
    }
    return dp[n-1];

}
int main(){
    string s;
    cin>>s;
    cout<<encodings(s)<<endl;

    return 0;
}