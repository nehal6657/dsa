#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i< n  ;i++)
        for(int j = 0; j < n - 1;j++)
            if(v[j+1] < v[j]) swap(v[j+1],v[j]);
        
}

int main(){
    vector<int> v1={12,16,27,7,6,2,1,0,14};
    bubble(v1);
    for(auto i: v1) cout<<i<< " ";

    return 0;
}