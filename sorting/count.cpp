#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

void count(vector<int> &v)
{
    int n=v.size();
    int m = *max_element(v.begin(),v.end());
    vector<int> ans(m+1,0);
    for(auto i: v)
        ans[i] ++;

    int i=0,j=0;
    while(j<=m){
        if(ans[j]){
            v[i++] = j;
            ans[j]--;
        }
        else j++;
    }


}

int main(){
    vector<int> v1{4,3,12,312,1,2,4,9,0};
    count(v1);
    for(auto x: v1) cout<<x<<" ";
    return 0;
}