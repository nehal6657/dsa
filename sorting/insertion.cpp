#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int> &v){
    int n = v.size();
    for(int i = 1 ; i < n  ;i++){
        int j = i-1;
        int x = v[i];
        while(j>=0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }   
        v[j+1] = x;
    } 
}

int main(){
    vector<int> v1={12,16,27,7,6,2,1,0,14};
    insertion(v1);
    for(auto i: v1) cout<<i<< " ";

    return 0;
}