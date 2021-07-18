#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;

int paintFence(int n, int k){
    if(n==1) return k;
    int ii = k, ij= k*(k-1);
    for(int i=3;i<=n;i++){
        int i2 = (ii+ij)*(k-1);
        int i21 = ij;
        ii = i21, ij = i2;
        cout<<ii<<" "<<ij<<endl;

    }
    return ii+ij;

}


int main(){
    int n,k;
    cin>>n>>k;
    cout<<paintFence(n,k)<<endl;
    
    return 0;
}