#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;


vs stair(int n){
    if(n==0){
        vs vx ={""}; return vx;
    }
    else if (n<0){
        vs vx={}; return vx;
    }

    vs v1 = stair(n-1);
    vs v2 = stair(n-2);
    vs v3 = stair(n-3);
    vs ans;
    for(auto i: v1){ ans.push_back('1'+i);}
    for(auto i: v2){ ans.push_back('2'+i);}
    for(auto i: v3){ ans.push_back('3'+i);}
    return ans;

}
void stair1 (int n, string s){
    if(n==0){
        cout<< s<<" ";
        return;
    }
    if(n<0) return ;
    stair1(n-1,s+"1");
    stair1(n-2,s+"2");
    stair1(n-3,s+"3");
}
 
int main(){
    vs ans = stair(4);
    for(auto i: ans) cout<<i<<" ";
    cout<<" \n nehal \n";
    stair1(4,"");
    return 0;
}