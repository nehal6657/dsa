#include<bits/stdc++.h>
using namespace std;
void selection(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i< n ;i++)
        {
            int k = i;
            for(int j = i; j<n;j++){
                if(v[j]< v[k]) k = j;
            }
            swap(v[i],v[k]);
        }

}

int main(){
    vector<int> v1={12,16,27,7,6,2,1,0,14};
    selection(v1);
    for(auto i: v1) cout<<i<< " ";

    return 0;
}